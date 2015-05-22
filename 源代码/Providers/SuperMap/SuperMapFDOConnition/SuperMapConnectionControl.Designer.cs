namespace SuperMapConnectionPlugin
{
    partial class SuperMapConnectionControl
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

        #region Component Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(SuperMapConnectionControl));
            this.datasourceTypeComboBox = new System.Windows.Forms.ComboBox();
            this.datasourceTypeLabel = new System.Windows.Forms.Label();
            this.datasourceInfoGroupBox = new System.Windows.Forms.GroupBox();
            this.passwordTextBox = new System.Windows.Forms.TextBox();
            this.passwordLabel = new System.Windows.Forms.Label();
            this.userTextBox = new System.Windows.Forms.TextBox();
            this.userLabel = new System.Windows.Forms.Label();
            this.dbNameTextBox = new System.Windows.Forms.TextBox();
            this.dbNameLabel = new System.Windows.Forms.Label();
            this.severComboBox = new System.Windows.Forms.ComboBox();
            this.fileButton = new System.Windows.Forms.Button();
            this.fileTextBox = new System.Windows.Forms.TextBox();
            this.severNameLabel = new System.Windows.Forms.Label();
            this.instanceTextBox = new System.Windows.Forms.TextBox();
            this.openModeGroupBox = new System.Windows.Forms.GroupBox();
            this.encryptCheckBox = new System.Windows.Forms.CheckBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.exclusiveRadioButton = new System.Windows.Forms.RadioButton();
            this.readOnlyRadioButton = new System.Windows.Forms.RadioButton();
            this.imageCheckBox = new System.Windows.Forms.CheckBox();
            this.openSDBDialog = new System.Windows.Forms.OpenFileDialog();
            this.lnkHomepage = new System.Windows.Forms.LinkLabel();
            this.SuperMapLogo = new System.Windows.Forms.PictureBox();
            this.datasourceInfoGroupBox.SuspendLayout();
            this.openModeGroupBox.SuspendLayout();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.SuperMapLogo)).BeginInit();
            this.SuspendLayout();
            // 
            // datasourceTypeComboBox
            // 
            this.datasourceTypeComboBox.Cursor = System.Windows.Forms.Cursors.Default;
            this.datasourceTypeComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.datasourceTypeComboBox.FormattingEnabled = true;
            this.datasourceTypeComboBox.Location = new System.Drawing.Point(0, 31);
            this.datasourceTypeComboBox.Name = "datasourceTypeComboBox";
            this.datasourceTypeComboBox.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.datasourceTypeComboBox.Size = new System.Drawing.Size(379, 20);
            this.datasourceTypeComboBox.TabIndex = 1;
            this.datasourceTypeComboBox.SelectedIndexChanged += new System.EventHandler(this.datasourceTypeChanged);
            // 
            // datasourceTypeLabel
            // 
            this.datasourceTypeLabel.AutoSize = true;
            this.datasourceTypeLabel.Location = new System.Drawing.Point(0, 12);
            this.datasourceTypeLabel.Name = "datasourceTypeLabel";
            this.datasourceTypeLabel.Size = new System.Drawing.Size(71, 12);
            this.datasourceTypeLabel.TabIndex = 1;
            this.datasourceTypeLabel.Text = "数据源类型:";
            // 
            // datasourceInfoGroupBox
            // 
            this.datasourceInfoGroupBox.Controls.Add(this.passwordTextBox);
            this.datasourceInfoGroupBox.Controls.Add(this.passwordLabel);
            this.datasourceInfoGroupBox.Controls.Add(this.userTextBox);
            this.datasourceInfoGroupBox.Controls.Add(this.userLabel);
            this.datasourceInfoGroupBox.Controls.Add(this.dbNameTextBox);
            this.datasourceInfoGroupBox.Controls.Add(this.dbNameLabel);
            this.datasourceInfoGroupBox.Controls.Add(this.severComboBox);
            this.datasourceInfoGroupBox.Controls.Add(this.fileButton);
            this.datasourceInfoGroupBox.Controls.Add(this.fileTextBox);
            this.datasourceInfoGroupBox.Controls.Add(this.severNameLabel);
            this.datasourceInfoGroupBox.Controls.Add(this.instanceTextBox);
            this.datasourceInfoGroupBox.Location = new System.Drawing.Point(0, 61);
            this.datasourceInfoGroupBox.Name = "datasourceInfoGroupBox";
            this.datasourceInfoGroupBox.Size = new System.Drawing.Size(379, 190);
            this.datasourceInfoGroupBox.TabIndex = 2;
            this.datasourceInfoGroupBox.TabStop = false;
            this.datasourceInfoGroupBox.Text = "数据源信息";
            // 
            // passwordTextBox
            // 
            this.passwordTextBox.Location = new System.Drawing.Point(9, 161);
            this.passwordTextBox.Name = "passwordTextBox";
            this.passwordTextBox.Size = new System.Drawing.Size(362, 21);
            this.passwordTextBox.TabIndex = 5;
            this.passwordTextBox.UseSystemPasswordChar = true;
            this.passwordTextBox.PreviewKeyDown += new System.Windows.Forms.PreviewKeyDownEventHandler(this.passwordTextBox_PreviewKeyDown);
            this.passwordTextBox.TextChanged += new System.EventHandler(this.passwordTextChanged);
            // 
            // passwordLabel
            // 
            this.passwordLabel.AutoSize = true;
            this.passwordLabel.Location = new System.Drawing.Point(9, 144);
            this.passwordLabel.Name = "passwordLabel";
            this.passwordLabel.Size = new System.Drawing.Size(35, 12);
            this.passwordLabel.TabIndex = 7;
            this.passwordLabel.Text = "密码:";
            // 
            // userTextBox
            // 
            this.userTextBox.Location = new System.Drawing.Point(9, 118);
            this.userTextBox.Name = "userTextBox";
            this.userTextBox.Size = new System.Drawing.Size(362, 21);
            this.userTextBox.TabIndex = 4;
            this.userTextBox.PreviewKeyDown += new System.Windows.Forms.PreviewKeyDownEventHandler(this.userTextBox_PreviewKeyDown);
            this.userTextBox.TextChanged += new System.EventHandler(this.userTextChanged);
            // 
            // userLabel
            // 
            this.userLabel.AutoSize = true;
            this.userLabel.Location = new System.Drawing.Point(9, 101);
            this.userLabel.Name = "userLabel";
            this.userLabel.Size = new System.Drawing.Size(59, 12);
            this.userLabel.TabIndex = 5;
            this.userLabel.Text = "用户名称:";
            // 
            // dbNameTextBox
            // 
            this.dbNameTextBox.Location = new System.Drawing.Point(9, 75);
            this.dbNameTextBox.Name = "dbNameTextBox";
            this.dbNameTextBox.Size = new System.Drawing.Size(362, 21);
            this.dbNameTextBox.TabIndex = 3;
            this.dbNameTextBox.PreviewKeyDown += new System.Windows.Forms.PreviewKeyDownEventHandler(this.dbNameTextBox_PreviewKeyDown);
            this.dbNameTextBox.TextChanged += new System.EventHandler(this.dbNameTextChanged);
            // 
            // dbNameLabel
            // 
            this.dbNameLabel.AutoSize = true;
            this.dbNameLabel.Location = new System.Drawing.Point(9, 59);
            this.dbNameLabel.Name = "dbNameLabel";
            this.dbNameLabel.Size = new System.Drawing.Size(71, 12);
            this.dbNameLabel.TabIndex = 3;
            this.dbNameLabel.Text = "数据库名称:";
            // 
            // severComboBox
            // 
            this.severComboBox.FormattingEnabled = true;
            this.severComboBox.Location = new System.Drawing.Point(89, 12);
            this.severComboBox.Name = "severComboBox";
            this.severComboBox.Size = new System.Drawing.Size(152, 20);
            this.severComboBox.TabIndex = 0;
            this.severComboBox.Visible = false;
            // 
            // fileButton
            // 
            this.fileButton.Image = ((System.Drawing.Image)(resources.GetObject("fileButton.Image")));
            this.fileButton.Location = new System.Drawing.Point(347, 32);
            this.fileButton.Name = "fileButton";
            this.fileButton.Size = new System.Drawing.Size(26, 21);
            this.fileButton.TabIndex = 2;
            this.fileButton.UseVisualStyleBackColor = true;
            this.fileButton.Click += new System.EventHandler(this.fileButton_Click);
            this.fileButton.KeyDown += new System.Windows.Forms.KeyEventHandler(this.fileButton_KeyDown);
            // 
            // fileTextBox
            // 
            this.fileTextBox.Location = new System.Drawing.Point(9, 34);
            this.fileTextBox.Name = "fileTextBox";
            this.fileTextBox.Size = new System.Drawing.Size(344, 21);
            this.fileTextBox.TabIndex = 0;
            this.fileTextBox.PreviewKeyDown += new System.Windows.Forms.PreviewKeyDownEventHandler(this.fileTextBox_PreviewKeyDown);
            this.fileTextBox.TextChanged += new System.EventHandler(this.filePathChanged);
            // 
            // severNameLabel
            // 
            this.severNameLabel.Location = new System.Drawing.Point(9, 16);
            this.severNameLabel.Name = "severNameLabel";
            this.severNameLabel.Size = new System.Drawing.Size(74, 12);
            this.severNameLabel.TabIndex = 0;
            this.severNameLabel.Text = "文件名:";
            // 
            // instanceTextBox
            // 
            this.instanceTextBox.Location = new System.Drawing.Point(8, 34);
            this.instanceTextBox.Name = "instanceTextBox";
            this.instanceTextBox.Size = new System.Drawing.Size(363, 21);
            this.instanceTextBox.TabIndex = 1;
            this.instanceTextBox.PreviewKeyDown += new System.Windows.Forms.PreviewKeyDownEventHandler(this.instanceTextBox_PreviewKeyDown);
            this.instanceTextBox.TextChanged += new System.EventHandler(this.instanceTextChanged);
            // 
            // openModeGroupBox
            // 
            this.openModeGroupBox.Controls.Add(this.encryptCheckBox);
            this.openModeGroupBox.Controls.Add(this.groupBox1);
            this.openModeGroupBox.Controls.Add(this.imageCheckBox);
            this.openModeGroupBox.Location = new System.Drawing.Point(0, 253);
            this.openModeGroupBox.Name = "openModeGroupBox";
            this.openModeGroupBox.Size = new System.Drawing.Size(379, 44);
            this.openModeGroupBox.TabIndex = 3;
            this.openModeGroupBox.TabStop = false;
            this.openModeGroupBox.Text = "连接选项";
            // 
            // encryptCheckBox
            // 
            this.encryptCheckBox.AutoSize = true;
            this.encryptCheckBox.Location = new System.Drawing.Point(100, 19);
            this.encryptCheckBox.Name = "encryptCheckBox";
            this.encryptCheckBox.Size = new System.Drawing.Size(48, 16);
            this.encryptCheckBox.TabIndex = 1;
            this.encryptCheckBox.Text = "加密";
            this.encryptCheckBox.UseVisualStyleBackColor = true;
            this.encryptCheckBox.Visible = false;
            this.encryptCheckBox.CheckedChanged += new System.EventHandler(this.encryptCheckBox_CheckedChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.exclusiveRadioButton);
            this.groupBox1.Controls.Add(this.readOnlyRadioButton);
            this.groupBox1.Location = new System.Drawing.Point(164, 7);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(117, 32);
            this.groupBox1.TabIndex = 7;
            this.groupBox1.TabStop = false;
            this.groupBox1.Visible = false;
            // 
            // exclusiveRadioButton
            // 
            this.exclusiveRadioButton.AutoSize = true;
            this.exclusiveRadioButton.Location = new System.Drawing.Point(64, 11);
            this.exclusiveRadioButton.Name = "exclusiveRadioButton";
            this.exclusiveRadioButton.Size = new System.Drawing.Size(47, 16);
            this.exclusiveRadioButton.TabIndex = 1;
            this.exclusiveRadioButton.TabStop = true;
            this.exclusiveRadioButton.Text = "独占";
            this.exclusiveRadioButton.UseVisualStyleBackColor = true;
            this.exclusiveRadioButton.Visible = false;
            // 
            // readOnlyRadioButton
            // 
            this.readOnlyRadioButton.AutoSize = true;
            this.readOnlyRadioButton.Location = new System.Drawing.Point(6, 11);
            this.readOnlyRadioButton.Name = "readOnlyRadioButton";
            this.readOnlyRadioButton.Size = new System.Drawing.Size(47, 16);
            this.readOnlyRadioButton.TabIndex = 0;
            this.readOnlyRadioButton.TabStop = true;
            this.readOnlyRadioButton.Text = "只读";
            this.readOnlyRadioButton.UseVisualStyleBackColor = true;
            this.readOnlyRadioButton.Visible = false;
            this.readOnlyRadioButton.CheckedChanged += new System.EventHandler(this.readOnlyRadioButton_CheckedChanged);
            // 
            // imageCheckBox
            // 
            this.imageCheckBox.AutoSize = true;
            this.imageCheckBox.Location = new System.Drawing.Point(9, 19);
            this.imageCheckBox.Name = "imageCheckBox";
            this.imageCheckBox.Size = new System.Drawing.Size(84, 16);
            this.imageCheckBox.TabIndex = 0;
            this.imageCheckBox.Text = "只读取影像";
            this.imageCheckBox.UseVisualStyleBackColor = true;
            this.imageCheckBox.CheckedChanged += new System.EventHandler(this.transactionCheckBox_CheckedChanged);
            // 
            // openSDBDialog
            // 
            this.openSDBDialog.Title = "打开文件";
            // 
            // lnkHomepage
            // 
            this.lnkHomepage.AutoSize = true;
            this.lnkHomepage.Location = new System.Drawing.Point(136, 10);
            this.lnkHomepage.Name = "lnkHomepage";
            this.lnkHomepage.Size = new System.Drawing.Size(161, 12);
            this.lnkHomepage.TabIndex = 4;
            this.lnkHomepage.TabStop = true;
            this.lnkHomepage.Text = "http://www.supermap.com.cn";
            this.lnkHomepage.Visible = false;
            this.lnkHomepage.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.lnkHomepage_LinkClicked);
            // 
            // SuperMapLogo
            // 
            this.SuperMapLogo.Cursor = System.Windows.Forms.Cursors.Hand;
            this.SuperMapLogo.Image = ((System.Drawing.Image)(resources.GetObject("SuperMapLogo.Image")));
            this.SuperMapLogo.Location = new System.Drawing.Point(299, 4);
            this.SuperMapLogo.Name = "SuperMapLogo";
            this.SuperMapLogo.Size = new System.Drawing.Size(80, 20);
            this.SuperMapLogo.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.SuperMapLogo.TabIndex = 5;
            this.SuperMapLogo.TabStop = false;
            this.SuperMapLogo.Click += new System.EventHandler(this.SuperMapLogo_Click);
            // 
            // SuperMapConnectionControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.Controls.Add(this.SuperMapLogo);
            this.Controls.Add(this.lnkHomepage);
            this.Controls.Add(this.openModeGroupBox);
            this.Controls.Add(this.datasourceInfoGroupBox);
            this.Controls.Add(this.datasourceTypeLabel);
            this.Controls.Add(this.datasourceTypeComboBox);
            this.Name = "SuperMapConnectionControl";
            this.Size = new System.Drawing.Size(402, 305);
            this.Load += new System.EventHandler(this.SuperMapConnectionControl_Load);
            this.datasourceInfoGroupBox.ResumeLayout(false);
            this.datasourceInfoGroupBox.PerformLayout();
            this.openModeGroupBox.ResumeLayout(false);
            this.openModeGroupBox.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.SuperMapLogo)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox datasourceTypeComboBox;
        private System.Windows.Forms.Label datasourceTypeLabel;
        private System.Windows.Forms.GroupBox datasourceInfoGroupBox;
        private System.Windows.Forms.Label severNameLabel;
        private System.Windows.Forms.TextBox fileTextBox;
        private System.Windows.Forms.Button fileButton;
        private System.Windows.Forms.TextBox instanceTextBox;
        private System.Windows.Forms.ComboBox severComboBox;
        private System.Windows.Forms.TextBox dbNameTextBox;
        private System.Windows.Forms.Label dbNameLabel;
        private System.Windows.Forms.TextBox passwordTextBox;
        private System.Windows.Forms.Label passwordLabel;
        private System.Windows.Forms.TextBox userTextBox;
        private System.Windows.Forms.Label userLabel;
        private System.Windows.Forms.GroupBox openModeGroupBox;
        private System.Windows.Forms.CheckBox imageCheckBox;
        private System.Windows.Forms.CheckBox encryptCheckBox;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton exclusiveRadioButton;
        private System.Windows.Forms.RadioButton readOnlyRadioButton;
        private System.Windows.Forms.OpenFileDialog openSDBDialog;
        private System.Windows.Forms.LinkLabel lnkHomepage;
        private System.Windows.Forms.PictureBox SuperMapLogo;
        //private System.Windows.Forms.LinkLabel lnkHelp;

    }
}
