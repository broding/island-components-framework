using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Xml.Linq;
using System.Collections;
using System.Collections.Specialized;
using System.IO;
using System.Security.Cryptography;


namespace Mozzerella
{
    enum Tool
    {
        SELECT = 0,
        DRAG
    }

    public partial class Mozzerella : Form
    {
        uint selectedId;
        Entity selectedEntity;
        Tool currentTool;

        public Mozzerella()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            currentTool = Tool.SELECT;
            selectedId = 0;

            componentsMenu.SelectedIndexChanged += LoadNewComponentData;
            dataGridView1.CellValueChanged += ComponentDataChanged;
            nameTextbox.TextChanged += NameChanged;

            addComponentToolStripMenuItem.DropDownItemClicked += addComponent_Click;

            FillAddComponentMenu();
        }

        private void SelectButton_Click(object sender, EventArgs e)
        {
            toolText.Text = "Select";
            currentTool = Tool.SELECT;
            GameCore.ChangeTool((int)Tool.SELECT);
        }

        private void DragButton_Click(object sender, EventArgs e)
        {
            toolText.Text = "Drag";
            currentTool = Tool.DRAG;
            GameCore.ChangeTool((int)Tool.DRAG);
        }

        private void ComponentDataChanged(object sender, EventArgs e)
        {
            foreach (DataGridViewRow row in dataGridView1.Rows)
                selectedEntity.UpdateComponentData(componentsMenu.SelectedIndex, row.Cells[0].Value.ToString(), row.Cells[1].Value.ToString());

            SendEntityXML();
        }

        private void FillAddComponentMenu()
        {
            string xml = Marshal.PtrToStringAnsi(GameCore.GetComponentXML());

            if (xml == null)
                return;

            XDocument doc = XDocument.Parse(xml);

            foreach (XElement component in doc.Element("components").Elements("component"))
                addComponentToolStripMenuItem.DropDownItems.Add(component.Attribute("name").Value).Tag = component.Attribute("type").Value;
        }

        private void NameChanged(object sender, EventArgs e)
        {
            selectedEntity.name = nameTextbox.Text;

            SendEntityXML();
        }

        private void SendEntityXML()
        {
            StringBuilder sb = new StringBuilder(selectedEntity.CreateXML().ToString());
            GameCore.SendEntityXML(sb, sb.Length);
        }

        private void LoadNewEntity()
        {
            string previousComponent = "";
            if (componentsMenu.SelectedIndex != -1)
                previousComponent = componentsMenu.SelectedItem.ToString();

            dataGridView1.Rows.Clear();
            componentsMenu.Items.Clear();
            componentsMenu.ResetText();

            string xml = Marshal.PtrToStringAnsi(GameCore.GetSelectedEntityXML());

            if (xml == null)
                return;

            selectedEntity = new Entity(XDocument.Parse(xml));

            idText.Text = selectedEntity.id.ToString();
            nameTextbox.Text = selectedEntity.name;

            foreach (string componentName in selectedEntity.GetComponentList())
                componentsMenu.Items.Add(componentName);

            // set the previous component index back to where is was
            for (int i = 0; i < componentsMenu.Items.Count; i++)
                if (componentsMenu.Items[i].ToString() == previousComponent)
                    componentsMenu.SelectedIndex = i;
        }

        private void LoadNewComponentData(object sender, EventArgs e)
        {
            dataGridView1.Rows.Clear();

            foreach (KeyValuePair<string, object> data in selectedEntity.GetComponentsData(componentsMenu.SelectedIndex)) 
                dataGridView1.Rows.Add(data.Key, data.Value);
        }

        new public void Update()
        {
            if (selectedId != 0)
                componentsToolStripMenuItem.Enabled = true;

            if (selectedId != GameCore.GetSelectedEntityId())
            {
                selectedId = GameCore.GetSelectedEntityId();
                LoadNewEntity();
            }
        }

        private void saveLevelToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string xml = Marshal.PtrToStringAnsi(GameCore.GetSceneXML());

            if (xml == null)
                return;

            XDocument document = XDocument.Parse(xml);

            SaveFileDialog save = new SaveFileDialog();
            save.Filter = "Scene (*.scn)|*.scn";
            save.Title = "Save Scene";

            if (save.ShowDialog() == DialogResult.OK) 
            {
                using (StreamWriter writer = new StreamWriter(save.OpenFile()))
                {
                    writer.WriteLine(EncryptString(document.ToString()));
                }
            } 
        }

        public string EncryptString(string ClearText)
        {

            byte[] clearTextBytes = Encoding.UTF8.GetBytes(ClearText);

            System.Security.Cryptography.SymmetricAlgorithm rijn = SymmetricAlgorithm.Create();

            MemoryStream ms = new MemoryStream();
            byte[] rgbIV = Encoding.ASCII.GetBytes("bcajvlzmdalyglrj");
            byte[] key = Encoding.ASCII.GetBytes("ccxilkqbbhczfeultgbskdmaunivmfuo"); 
            CryptoStream cs = new CryptoStream(ms, rijn.CreateEncryptor(key, rgbIV),CryptoStreamMode.Write);

            cs.Write(clearTextBytes, 0, clearTextBytes.Length);

            cs.Close();

            return Convert.ToBase64String(ms.ToArray());
        }

        private string DecryptString(string EncryptedText)
        {
            byte[] encryptedTextBytes = Convert.FromBase64String(EncryptedText);

            MemoryStream ms = new MemoryStream();

            System.Security.Cryptography.SymmetricAlgorithm rijn = SymmetricAlgorithm.Create();

            byte[] rgbIV = Encoding.ASCII.GetBytes("bcajvlzmdalyglrj");
            byte[] key = Encoding.ASCII.GetBytes("ccxilkqbbhczfeultgbskdmaunivmfuo"); 

            CryptoStream cs = new CryptoStream(ms, rijn.CreateDecryptor(key, rgbIV),
            CryptoStreamMode.Write);

            cs.Write(encryptedTextBytes, 0, encryptedTextBytes.Length);

            cs.Close();

            return Encoding.UTF8.GetString(ms.ToArray());
        }

        private void newSceneToolStripMenuItem_Click(object sender, EventArgs e)
        {
            GameCore.ClearScene();
        }

        private void loadLevelToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.Filter = "Scene (*.scn)|*.scn";
            dialog.Title = "Load Scene";

            if (dialog.ShowDialog() == DialogResult.OK)
            {
                string text = DecryptString(File.ReadAllText(dialog.FileName));
            } 
        }

        private void addEntityToolStripMenuItem_Click(object sender, EventArgs e)
        {
            GameCore.AddEntity();
        }

        private void addComponent_Click(object sender, ToolStripItemClickedEventArgs e)
        {
            string componentName = e.ClickedItem.Text;

            GameCore.AddComponent(int.Parse(e.ClickedItem.Tag.ToString()));
            RefreshSelectedEntity();

            // set the previous component index back to the component added
            for (int i = 0; i < componentsMenu.Items.Count; i++)
                if (componentsMenu.Items[i].ToString() == componentName)
                    componentsMenu.SelectedIndex = i;
        }

        private void RefreshSelectedEntity()
        {
            LoadNewEntity();
        }
    }
}
