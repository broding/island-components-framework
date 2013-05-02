using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;


namespace Mozzerella
{
    enum Tool
    {
        SELECT = 0,
        DRAG
    }

    public partial class Mozzerella : Form
    {
        Tool currentTool;

        public Mozzerella()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
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
    }
}
