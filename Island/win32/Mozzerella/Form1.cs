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
        }

        private void SelectButton_Click(object sender, EventArgs e)
        {
            currentTool = Tool.SELECT;
            GameCore.ChangeTool((int)Tool.SELECT);
        }

        private void DragButton_Click(object sender, EventArgs e)
        {
            currentTool = Tool.DRAG;
            GameCore.ChangeTool((int)Tool.DRAG);
        }

        private void ComponentDataChanged(object sender, EventArgs e)
        {
            foreach (DataGridViewRow row in dataGridView1.Rows)
                selectedEntity.UpdateComponentData(componentsMenu.SelectedIndex, row.Cells[0].Value.ToString(), row.Cells[1].Value.ToString());

            SendEntityXML();
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
            if (selectedId != GameCore.GetSelectedEntityId())
            {
                selectedId = GameCore.GetSelectedEntityId();
                LoadNewEntity();
            }
        }
    }
}
