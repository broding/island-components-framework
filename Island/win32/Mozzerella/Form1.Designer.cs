namespace Mozzerella
{
    partial class Mozzerella
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Mozzerella));
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.SelectButton = new System.Windows.Forms.ToolStripButton();
            this.DragButton = new System.Windows.Forms.ToolStripButton();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.levelToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.newSceneToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.loadLevelToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveLevelToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.entityToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.addEntityToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.componentsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.addComponentToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.inspector = new System.Windows.Forms.GroupBox();
            this.componentDataGroup = new System.Windows.Forms.GroupBox();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.label1 = new System.Windows.Forms.Label();
            this.componentsMenu = new System.Windows.Forms.ComboBox();
            this.nameTextbox = new System.Windows.Forms.TextBox();
            this.nameLabel = new System.Windows.Forms.Label();
            this.idText = new System.Windows.Forms.Label();
            this.idLabel = new System.Windows.Forms.Label();
            this.toolText = new System.Windows.Forms.Label();
            this.type = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Value = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.entities = new System.Windows.Forms.GroupBox();
            this.entityList = new System.Windows.Forms.ListBox();
            this.toolStrip1.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.inspector.SuspendLayout();
            this.componentDataGroup.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.entities.SuspendLayout();
            this.SuspendLayout();
            // 
            // toolStrip1
            // 
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.SelectButton,
            this.DragButton});
            this.toolStrip1.Location = new System.Drawing.Point(0, 24);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.ShowItemToolTips = false;
            this.toolStrip1.Size = new System.Drawing.Size(429, 25);
            this.toolStrip1.TabIndex = 0;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // SelectButton
            // 
            this.SelectButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.SelectButton.Image = ((System.Drawing.Image)(resources.GetObject("SelectButton.Image")));
            this.SelectButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.SelectButton.Name = "SelectButton";
            this.SelectButton.Size = new System.Drawing.Size(23, 22);
            this.SelectButton.Text = "Select entity";
            this.SelectButton.Click += new System.EventHandler(this.SelectButton_Click);
            // 
            // DragButton
            // 
            this.DragButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.DragButton.Image = ((System.Drawing.Image)(resources.GetObject("DragButton.Image")));
            this.DragButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.DragButton.Name = "DragButton";
            this.DragButton.Size = new System.Drawing.Size(23, 22);
            this.DragButton.Text = "Drag entity";
            this.DragButton.Click += new System.EventHandler(this.DragButton_Click);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.levelToolStripMenuItem,
            this.entityToolStripMenuItem,
            this.componentsToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(429, 24);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // levelToolStripMenuItem
            // 
            this.levelToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newSceneToolStripMenuItem,
            this.loadLevelToolStripMenuItem,
            this.saveLevelToolStripMenuItem});
            this.levelToolStripMenuItem.Name = "levelToolStripMenuItem";
            this.levelToolStripMenuItem.Size = new System.Drawing.Size(50, 20);
            this.levelToolStripMenuItem.Text = "Scene";
            // 
            // newSceneToolStripMenuItem
            // 
            this.newSceneToolStripMenuItem.Name = "newSceneToolStripMenuItem";
            this.newSceneToolStripMenuItem.Size = new System.Drawing.Size(134, 22);
            this.newSceneToolStripMenuItem.Text = "New Scene";
            this.newSceneToolStripMenuItem.Click += new System.EventHandler(this.newSceneToolStripMenuItem_Click);
            // 
            // loadLevelToolStripMenuItem
            // 
            this.loadLevelToolStripMenuItem.Name = "loadLevelToolStripMenuItem";
            this.loadLevelToolStripMenuItem.Size = new System.Drawing.Size(134, 22);
            this.loadLevelToolStripMenuItem.Text = "Load Scene";
            this.loadLevelToolStripMenuItem.Click += new System.EventHandler(this.loadLevelToolStripMenuItem_Click);
            // 
            // saveLevelToolStripMenuItem
            // 
            this.saveLevelToolStripMenuItem.Name = "saveLevelToolStripMenuItem";
            this.saveLevelToolStripMenuItem.Size = new System.Drawing.Size(134, 22);
            this.saveLevelToolStripMenuItem.Text = "Save Scene";
            this.saveLevelToolStripMenuItem.Click += new System.EventHandler(this.saveLevelToolStripMenuItem_Click);
            // 
            // entityToolStripMenuItem
            // 
            this.entityToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.addEntityToolStripMenuItem});
            this.entityToolStripMenuItem.Name = "entityToolStripMenuItem";
            this.entityToolStripMenuItem.Size = new System.Drawing.Size(49, 20);
            this.entityToolStripMenuItem.Text = "Entity";
            // 
            // addEntityToolStripMenuItem
            // 
            this.addEntityToolStripMenuItem.Name = "addEntityToolStripMenuItem";
            this.addEntityToolStripMenuItem.Size = new System.Drawing.Size(129, 22);
            this.addEntityToolStripMenuItem.Text = "Add Entity";
            this.addEntityToolStripMenuItem.Click += new System.EventHandler(this.addEntityToolStripMenuItem_Click);
            // 
            // componentsToolStripMenuItem
            // 
            this.componentsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.addComponentToolStripMenuItem});
            this.componentsToolStripMenuItem.Enabled = false;
            this.componentsToolStripMenuItem.Name = "componentsToolStripMenuItem";
            this.componentsToolStripMenuItem.Size = new System.Drawing.Size(88, 20);
            this.componentsToolStripMenuItem.Text = "Components";
            // 
            // addComponentToolStripMenuItem
            // 
            this.addComponentToolStripMenuItem.Name = "addComponentToolStripMenuItem";
            this.addComponentToolStripMenuItem.Size = new System.Drawing.Size(163, 22);
            this.addComponentToolStripMenuItem.Text = "Add Component";
            // 
            // inspector
            // 
            this.inspector.Controls.Add(this.componentDataGroup);
            this.inspector.Controls.Add(this.label1);
            this.inspector.Controls.Add(this.componentsMenu);
            this.inspector.Controls.Add(this.nameTextbox);
            this.inspector.Controls.Add(this.nameLabel);
            this.inspector.Controls.Add(this.idText);
            this.inspector.Controls.Add(this.idLabel);
            this.inspector.Location = new System.Drawing.Point(203, 52);
            this.inspector.Name = "inspector";
            this.inspector.Size = new System.Drawing.Size(219, 410);
            this.inspector.TabIndex = 2;
            this.inspector.TabStop = false;
            this.inspector.Text = "Inspector";
            // 
            // componentDataGroup
            // 
            this.componentDataGroup.Controls.Add(this.dataGridView1);
            this.componentDataGroup.Location = new System.Drawing.Point(12, 123);
            this.componentDataGroup.Name = "componentDataGroup";
            this.componentDataGroup.Size = new System.Drawing.Size(190, 283);
            this.componentDataGroup.TabIndex = 8;
            this.componentDataGroup.TabStop = false;
            this.componentDataGroup.Text = "Data";
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.AllowUserToDeleteRows = false;
            this.dataGridView1.AllowUserToResizeColumns = false;
            this.dataGridView1.AllowUserToResizeRows = false;
            this.dataGridView1.BackgroundColor = System.Drawing.SystemColors.Menu;
            this.dataGridView1.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.ColumnHeadersVisible = false;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.type,
            this.Value});
            this.dataGridView1.Location = new System.Drawing.Point(6, 19);
            this.dataGridView1.MultiSelect = false;
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersVisible = false;
            this.dataGridView1.RowTemplate.Resizable = System.Windows.Forms.DataGridViewTriState.False;
            this.dataGridView1.Size = new System.Drawing.Size(178, 258);
            this.dataGridView1.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(9, 80);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(69, 13);
            this.label1.TabIndex = 7;
            this.label1.Text = "Components:";
            // 
            // componentsMenu
            // 
            this.componentsMenu.Location = new System.Drawing.Point(12, 96);
            this.componentsMenu.Name = "componentsMenu";
            this.componentsMenu.Size = new System.Drawing.Size(190, 21);
            this.componentsMenu.TabIndex = 6;
            // 
            // nameTextbox
            // 
            this.nameTextbox.Location = new System.Drawing.Point(62, 48);
            this.nameTextbox.Name = "nameTextbox";
            this.nameTextbox.Size = new System.Drawing.Size(140, 20);
            this.nameTextbox.TabIndex = 3;
            // 
            // nameLabel
            // 
            this.nameLabel.AutoSize = true;
            this.nameLabel.Location = new System.Drawing.Point(9, 51);
            this.nameLabel.Name = "nameLabel";
            this.nameLabel.Size = new System.Drawing.Size(38, 13);
            this.nameLabel.TabIndex = 5;
            this.nameLabel.Text = "Name:";
            // 
            // idText
            // 
            this.idText.AutoSize = true;
            this.idText.Location = new System.Drawing.Point(59, 26);
            this.idText.Name = "idText";
            this.idText.Size = new System.Drawing.Size(0, 13);
            this.idText.TabIndex = 4;
            // 
            // idLabel
            // 
            this.idLabel.AutoSize = true;
            this.idLabel.Location = new System.Drawing.Point(9, 26);
            this.idLabel.Name = "idLabel";
            this.idLabel.Size = new System.Drawing.Size(19, 13);
            this.idLabel.TabIndex = 3;
            this.idLabel.Text = "Id:";
            // 
            // toolText
            // 
            this.toolText.AutoSize = true;
            this.toolText.Location = new System.Drawing.Point(72, 31);
            this.toolText.Name = "toolText";
            this.toolText.Size = new System.Drawing.Size(37, 13);
            this.toolText.TabIndex = 3;
            this.toolText.Text = "Select";
            this.toolText.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // type
            // 
            this.type.HeaderText = "type";
            this.type.Name = "type";
            this.type.ReadOnly = true;
            this.type.Resizable = System.Windows.Forms.DataGridViewTriState.False;
            // 
            // Value
            // 
            this.Value.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.Value.HeaderText = "Value";
            this.Value.Name = "Value";
            this.Value.Resizable = System.Windows.Forms.DataGridViewTriState.False;
            // 
            // entities
            // 
            this.entities.Controls.Add(this.entityList);
            this.entities.Location = new System.Drawing.Point(12, 52);
            this.entities.Name = "entities";
            this.entities.Size = new System.Drawing.Size(179, 410);
            this.entities.TabIndex = 4;
            this.entities.TabStop = false;
            this.entities.Text = "Entities";
            // 
            // entityList
            // 
            this.entityList.FormattingEnabled = true;
            this.entityList.Location = new System.Drawing.Point(12, 20);
            this.entityList.Name = "entityList";
            this.entityList.Size = new System.Drawing.Size(157, 381);
            this.entityList.TabIndex = 0;
            // 
            // Mozzerella
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoValidate = System.Windows.Forms.AutoValidate.Disable;
            this.ClientSize = new System.Drawing.Size(429, 469);
            this.Controls.Add(this.entities);
            this.Controls.Add(this.toolText);
            this.Controls.Add(this.inspector);
            this.Controls.Add(this.toolStrip1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Mozzerella";
            this.Text = "Mozzerella";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.inspector.ResumeLayout(false);
            this.inspector.PerformLayout();
            this.componentDataGroup.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.entities.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem levelToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem loadLevelToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveLevelToolStripMenuItem;
        private System.Windows.Forms.ToolStripButton DragButton;
        private System.Windows.Forms.ToolStripButton SelectButton;
        private System.Windows.Forms.GroupBox inspector;
        private System.Windows.Forms.Label idLabel;
        private System.Windows.Forms.Label idText;
        private System.Windows.Forms.Label nameLabel;
        private System.Windows.Forms.TextBox nameTextbox;
        private System.Windows.Forms.ComboBox componentsMenu;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox componentDataGroup;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Label toolText;
        private System.Windows.Forms.ToolStripMenuItem newSceneToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem entityToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem addEntityToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem componentsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem addComponentToolStripMenuItem;
        private System.Windows.Forms.DataGridViewTextBoxColumn type;
        private System.Windows.Forms.DataGridViewTextBoxColumn Value;
        private System.Windows.Forms.GroupBox entities;
        private System.Windows.Forms.ListBox entityList;
    }
}

