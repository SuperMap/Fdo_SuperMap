using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;
using Autodesk.Gis.Map.DataConnect.Plugins;


using System.Diagnostics;


namespace SuperMapConnectionPlugin
{


    [DataConnectPluginAttribute("SuperMap.SuperMap SDX.1.0")]
    public partial class SuperMapConnectionControl : UserControl
            , IDataConnectConnectionPlugin
    {

#if LANGUAGE_ZH_CN
        protected const string strDatasourceTypeLabel = "数据源类型:";
        protected const string strDatasourceInfoGroupBox = "数据源信息";
        protected const string strSeverNameLabel = "文件名:";
        protected const string strSeverNameLabelDb = "服务器名称:";
        protected const string strSeverNameLabelIntance = "实例名称:";
        protected const string strDbNameLabel = "数据库名称:";
        protected const string strUserLabel = "用户名称:";
        protected const string strPasswordLabel = "密码:";
        protected const string strOpenModeGroupBox = "连接选项";
        protected const string strImageCheckBox = "只读取影像";
        protected const string strEncryptCheckBox = "加密";
        protected const string strReadOnlyRadioButton = "只读";
        protected const string strExclusiveRadioButton = "独占";

        protected const string strSdbEng = "SuperMap SDB Plus 文件(*.SDB)";
        protected const string strSITEng = "SuperMap SIT 影像文件(*.SIT)";
        protected const string strSQLEng = "SQL Plus 数据源";
        protected const string strOracleEng = "Oracle 数据源";

        protected const string strOpenFile = "打开文件";
        protected const string strErrNoUseFunction = "系统错误,不能使用该功能!";

        protected const string strlnkHomepage = "http://www.supermap.com.cn";
        //protected const string strlnkHelp = "帮助";

#else
        protected const string strDatasourceTypeLabel = "DataSource Type:";
        protected const string strDatasourceInfoGroupBox = "DataSource Information";
        protected const string strSeverNameLabel = "File";
        protected const string strSeverNameLabelDb = "Server";
        protected const string strSeverNameLabelIntance = "Instance";
        protected const string strDbNameLabel = "Database:";
        protected const string strUserLabel = "User:";
        protected const string strPasswordLabel = "Password:";
        protected const string strOpenModeGroupBox = "Connection Option";
        protected const string strImageCheckBox = "Only read Image";
        protected const string strEncryptCheckBox = "Encrypt";
        protected const string strReadOnlyRadioButton = "Read Only";
        protected const string strExclusiveRadioButton = "Exclusive";

        protected const string strSdbEng = "SuperMap SDB Plus File(*.SDB)";
        protected const string strSITEng = "SuperMap Image File(*.SIT)";
        protected const string strSQLEng = "SQL Plus DataSource";
        protected const string strOracleEng = "Oracle DataSource";

        protected const string strOpenFile = "Open File";
        protected const string strErrNoUseFunction = "System Error!This function is disabled!";

        protected const string strlnkHomepage = "http://www.supermap.com";
        protected const string strlnkHelp = "help";
#endif


        public SuperMapConnectionControl()
        {
            InitializeComponent();

            this.datasourceTypeComboBox.Items.AddRange(new object[] {
            strSdbEng,//"SuperMap SDB文件(*.SDB)",
            strSITEng, //"SuperMap SIT影像文件(*.SIT)",
            strSQLEng, //"SQL数据源",
            strOracleEng //"Oracle数据源"
            });
            this.datasourceTypeLabel.Text = strDatasourceTypeLabel;// "数据源类型:";
            this.datasourceInfoGroupBox.Text = strDatasourceInfoGroupBox;// "数据源信息";
            this.passwordLabel.Text = strPasswordLabel;// "密码:";
            this.userLabel.Text = strUserLabel;// "用户名称:";
            this.dbNameLabel.Text = strDbNameLabel;// "数据库名称:";
            this.severNameLabel.Text = strSeverNameLabel;// "文件名:";
            this.openModeGroupBox.Text = strOpenModeGroupBox;// "连接选项";
            this.encryptCheckBox.Text = strEncryptCheckBox;// "加密";
            this.exclusiveRadioButton.Text = strExclusiveRadioButton;// "独占";
            this.readOnlyRadioButton.Text = strReadOnlyRadioButton;// "只读";
            this.imageCheckBox.Text = strImageCheckBox;// "只读取影像";
            this.openSDBDialog.Title = strOpenFile;// "打开文件";

            //this.lnkHelp.Text = strlnkHelp;
            this.lnkHomepage.Text = strlnkHomepage;

            this.datasourceTypeComboBox.SelectedIndex = 0;

            bInitialize = true;

            //DEBUG_TRACE("Initializing SuperMapConnectionControl and  checkConnectionParametersValid ...");
        }

        #region IDataConnectPlugin implementation
        // IDataConnectPlugin implementation
        protected IDataConnectPluginHost m_host;
        //protected string m_providerName;

        public void Attach(IDataConnectPluginHost host)
        {
            //DEBUG_TRACE("Attach host");

            m_host = host;
        }

        public void Detach() { m_host = null; }

        public IDataConnectPluginHost Host
        {
            get
            {
                return m_host;
            }
        }

        public UserControl ClientControl
        {
            get
            {
                return this;
            }
        }

        #endregion

        #region IPlugin implementation
        // IPlugin implementation

#if CHINESE
        protected string title = "title";
        protected string description = "description";
        protected string company = "SuperMap GIS Technologies, Inc";
        protected string version = "1.0.0";
        protected Type[] dependencies;
#else
        protected string title = "title";
        protected string description = "description";
        protected string company = "SuperMap GIS Technologies, Inc";
        protected string version = "1.0.0";
        protected Type[] dependencies;
#endif



        public string Title
        {
            get
            {
                return title;
            }

            set
            {
                title = value;
            }
        }

        public string Description
        {
            get
            {
                return description;
            }
            set
            {
                description = value;
            }
        }

        public string Company
        {
            get
            {
                return company;
            }
            set
            {
                company = value;
            }
        }

        public string Version
        {
            get
            {
                return version;
            }
            set
            {
                version = value;
            }
        }

        public Type[] Dependencies
        {
            get
            {
                return dependencies;
            }
        }

        #endregion

        #region IDataConnectConnectionPlugin Property

        private Dictionary<string, string> m_connection = new Dictionary<string, string>();
        private bool m_isParametersValid = false;
        private string m_ProviderName;// = "SuperMap.SDB&SDX.1.0";
        public string[] ConnectionParameterNames
        {
            get
            {
                //DEBUG_TRACE("Getting ConnectionParameterNames ...");

                string[] names = new string[this.m_connection.Keys.Count];
                this.m_connection.Keys.CopyTo(names, 0);

                return names;
            }
        }

        public bool ConnectionParametersValid
        {
            get
            {
                return m_isParametersValid;
            }
        }

        public string ProviderName
        {
            get
            {
                return m_ProviderName;
            }
        }

        #endregion

        #region IDataConnectConnectionPlugin methods

        public string GetConnectionParameter(string name)
        {
            //DEBUG_TRACE("进入函数GetConnectionParameter. ConnectionParameter " + name + " is " + this.m_connection[name]);

            try
            {
                return this.m_connection[name];
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
                return "";
            }
        }

        public void Initialize(string providerName)
        {
            m_ProviderName = providerName;
        }

        public void SetConnectionParameter(string name, string value)
        {
            this.m_connection[name] = value;
        }

        public void SetConnectionParametersToDefaults()
        {
            if (!bInitialize)   //初始化的时候将所有值置为空
            {
                m_connection.Clear();
                m_isParametersValid = false;
            }
            else   //如果选择了SuperMap Provider,然后又点选了其他Provider,再回来的时候需要将其设为上次的值        
            {
                checkConnectionParametersValid();
            }
        }

        #endregion


        #region IDataConnectConnectionPlugin event
        public event ParameterValueChangedEventHandler ParameterValueChangedEvent;
        #endregion

        //向内部传送信息时连接类型名称
        const string sdbConnName = "sdb";
        const string sqlConnName = "sql";
        const string sitConnName = "sit";
        const string sqlPlusConnName = "sql+";
        const string oracleConnName = "ora";
        const string oracleSpatialConnName = "oracle spatial";

        /// <summary>
        /// 检查参数是否有效,当有效的时候发送ParameterValueChangedEvent信息,通知Map3D连接按钮可激活
        /// </summary>
        private void checkConnectionParametersValid()
        {
            try
            {
                //如果是还没有初始化,控件还没有创建,执行的时候是会出错的
                if (!bInitialize)
                {
                    return;
                }

                //DEBUG_TRACE("进入函数checkConnectionParametersValid检查参数有效性 ... ");

                string strDataSource = "";		//L"数据源";
                string strServer = "";  //L"server";
                string strUser = "";	//L"user";
                string strPassword = "";	//L"password";
                string strConnType = "";    //L"type";
                string strDatabase = "";    //L"database";
                // added by zhouxu 2008-1-17
                string strIsImage = "false";   //true表示以影像模式打开，默认为非影像模式打开

                ///
                ///首先参数复位
                ///
                m_connection.Clear();
                m_isParametersValid = false;

                ///
                ///然后从界面中取出相关连接参数值
                ///
                //数据源类型
                if (0 == this.datasourceTypeComboBox.SelectedIndex)
                {   // "sdb";
                    strConnType = sdbConnName;
                    //this.imageCheckBox.Checked = false;
                    //this.imageCheckBox.Enabled = true;
                }
                else if (1 == this.datasourceTypeComboBox.SelectedIndex)
                {   // "sit"
                    strConnType = sitConnName;
                    //this.imageCheckBox.Checked = true;
                    //this.imageCheckBox.Enabled = false;
                }
                else if (2 == this.datasourceTypeComboBox.SelectedIndex)
                {   // "sql";
                    strConnType = sqlConnName;
                    //this.imageCheckBox.Checked = false;
                    //this.imageCheckBox.Enabled = true;
                }
                else if (3 == this.datasourceTypeComboBox.SelectedIndex)
                {   // "oracle";
                    strConnType = oracleConnName;
                    //this.imageCheckBox.Checked = false;
                    //this.imageCheckBox.Enabled = true;
                }
                else
                {
                    strConnType = "";
                }

                //文件数据源参数
                if (0 == this.datasourceTypeComboBox.SelectedIndex ||
                    1 == this.datasourceTypeComboBox.SelectedIndex)
                {
                    strDatabase = fileTextBox.Text;
                    strDatabase.Trim();

                    if (bEncrypt)
                    {
                        strPassword = passwordTextBox.Text;
                    }
                }
                else
                {   //SQL、SQL+、Oracle、或OracleSpatial数据源参数

                    //服务器名
                    strServer = instanceTextBox.Text;
                    strServer.Trim();

                    //数据库名
                    strDatabase = dbNameTextBox.Text;
                    strDatabase.Trim();

                    //用户名
                    strUser = userTextBox.Text;
                    strUser.Trim();

                    //密码
                    strPassword = passwordTextBox.Text;
                }

                // 是否影像模式打开 added by zhouxu 2008-1-17
                if (this.imageCheckBox.Checked)
                {
                    strIsImage = "true";
                }

                ///
                ///进行参数有效性验证
                ///
                if (0 == strConnType.Length)
                {
                    //DEBUG_TRACE("连接类型长度为0，发送ParameterValueChangedEvent事件,参数无效 ... ");

                    ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                    m_isParametersValid = false;
                    return;
                }
                else if (sdbConnName == strConnType)
                {
                    if (strDatabase.Length <= 0)
                    {
                        //DEBUG_TRACE("数据库长度为0，发送ParameterValueChangedEvent事件,参数无效 ... ");

                        ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                        m_isParametersValid = false;
                        return;
                    }

                    if (bEncrypt)
                    {
                        if (strPassword.Length <= 0)
                        {
                            //DEBUG_TRACE("密码长度为0，发送ParameterValueChangedEvent事件,参数无效 ... ");

                            ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                            m_isParametersValid = false;
                            return;
                        }
                    }

                    this.m_connection.Clear();
                    strDataSource = "type=" + strConnType + ";database=" + strDatabase;
                    if (bEncrypt)
                    {
                        strDataSource += ";password=" + strPassword;
                    }
                    strDataSource += ";IsImage=" + strIsImage;  // added by zhouxu 2008-1-17 
                    SetConnectionParameter("DataSource", strDataSource);
                    m_isParametersValid = true;

                    //DEBUG_TRACE("发送ParameterValueChangedEvent事件,参数有效 !!!. ");

                    ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                    return;
                }
                else if (sitConnName == strConnType)
                {
                    if (strDatabase.Length <= 0)
                    {
                        //DEBUG_TRACE("数据库长度为0，发送ParameterValueChangedEvent事件,参数无效 ... ");

                        ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                        m_isParametersValid = false;
                        return;
                    }

                    this.m_connection.Clear();
                    strDataSource = "type=" + strConnType + ";database=" + strDatabase;

                    strDataSource += ";IsImage=" + strIsImage;
                    SetConnectionParameter("DataSource", strDataSource);
                    m_isParametersValid = true;

                    ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                    return;
                }
                else if (sqlConnName == strConnType || sqlPlusConnName == strConnType
                    || oracleConnName == strConnType || oracleSpatialConnName == strConnType)
                {
                    if (strServer.Length <= 0)
                    {
                        //DEBUG_TRACE("服务器长度为0，发送ParameterValueChangedEvent事件,参数无效 ... ");

                        ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                        m_isParametersValid = false;
                        return;
                    }

                    if (strDatabase.Length <= 0)
                    {
                        //DEBUG_TRACE("数据库长度为0，发送ParameterValueChangedEvent事件,参数无效 ... ");

                        ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                        m_isParametersValid = false;
                        return;
                    }

                    if (strUser.Length <= 0)
                    {
                        //DEBUG_TRACE("用户长度为0，发送ParameterValueChangedEvent事件,参数无效 ... ");

                        ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                        m_isParametersValid = false;
                        return;
                    }

                    if (strPassword.Length <= 0)
                    {
                        //DEBUG_TRACE("密码长度为0，发送ParameterValueChangedEvent事件,参数无效 ... ");

                        ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                        m_isParametersValid = false;
                        return;
                    }

                    this.m_connection.Clear();
                    strDataSource = "type=" + strConnType + ";server=" + strServer + ";database=" + strDatabase +
                        ";user=" + strUser + ";password=" + strPassword;
                    strDataSource += ";IsImage=" + strIsImage;  // added by zhouxu 2008-1-17 
                    SetConnectionParameter("DataSource", strDataSource);
                    m_isParametersValid = true;

                    //DEBUG_TRACE("发送ParameterValueChangedEvent事件,参数有效 !!!. ");

                    ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                    return;
                }

                m_isParametersValid = false;
                ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                return;
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
            }
            finally
            {
            }
        }



        private bool bEncrypt = false;
        private string strSdbFilePath = "";
        private bool bInitialize = false;

        private void fileButton_Click(object sender, EventArgs e)
        {
            try
            {
                DialogResult responseDialogResult;
                openSDBDialog.InitialDirectory = Application.StartupPath;

                if (this.datasourceTypeComboBox.SelectedIndex == 0)
                    openSDBDialog.Filter = "SuperMap SDB Files(*.sdb)|*.sdb";
                else
                    openSDBDialog.Filter = "SuperMap SIT Files(*.SIT)|*.SIT";

                responseDialogResult = openSDBDialog.ShowDialog();

                if (DialogResult.Cancel != responseDialogResult)
                {
                    strSdbFilePath = openSDBDialog.FileName;
                    this.fileTextBox.Text = strSdbFilePath;
                }
            }
            catch (Exception ec)
            {
                MessageBox.Show(ec.Message);
            }
        }

        /// <summary>
        /// 相关参数改变事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void datasourceTypeChanged(object sender, EventArgs e)
        {
            //DEBUG_TRACE("进入函数datasourceTypeChanged ... ");

            try
            {
                //将连接信息归零
                SetConnectionParametersToDefaults();

                switch (this.datasourceTypeComboBox.SelectedIndex)
                {
                    case 0: //文件
                        {
                            ///
                            ///数据源信息
                            ///
                            //设置文件名信息
                            this.severNameLabel.Text = strSeverNameLabel;// "文件名";
                            this.fileTextBox.Show();
                            this.fileButton.Show();
                            this.instanceTextBox.Hide();

                            //数据库名称
                            this.dbNameLabel.Enabled = false;
                            this.dbNameTextBox.Enabled = false;

                            //用户名称
                            this.userLabel.Enabled = false;
                            this.userTextBox.Enabled = false;

                            //密码
                            this.passwordLabel.Enabled = bEncrypt;
                            this.passwordTextBox.Enabled = bEncrypt;

                            this.imageCheckBox.Checked = false;
                            this.imageCheckBox.Enabled = true;

                        }
                        break;
                    case 1: //SIT文件
                        {
                            ///
                            ///数据源信息
                            ///
                            //设置文件名信息
                            this.severNameLabel.Text = strSeverNameLabel;// "文件名";
                            this.fileTextBox.Show();
                            this.fileButton.Show();
                            this.instanceTextBox.Hide();

                            //数据库名称
                            this.dbNameLabel.Enabled = false;
                            this.dbNameTextBox.Enabled = false;

                            //用户名称
                            this.userLabel.Enabled = false;
                            this.userTextBox.Enabled = false;

                            //密码
                            this.passwordLabel.Enabled = false;
                            this.passwordTextBox.Enabled = false;

                            this.imageCheckBox.Checked = true;
                            this.imageCheckBox.Enabled = false;

                        }
                        break;
                    case 2: //SQL数据源
                        {
                            ///
                            ///数据源信息
                            ///
                            //设置服务器名称
                            this.severNameLabel.Text = strSeverNameLabelDb;// "服务器名称";
                            this.fileTextBox.Hide();
                            this.fileButton.Hide();
                            this.instanceTextBox.Show();

                            //数据库名称
                            this.dbNameLabel.Enabled = true;
                            this.dbNameTextBox.Enabled = true;

                            //用户名称
                            this.userLabel.Enabled = true;
                            this.userTextBox.Enabled = true;

                            //密码
                            this.passwordLabel.Enabled = true;
                            this.passwordTextBox.Enabled = true;

                            this.imageCheckBox.Checked = false;
                            this.imageCheckBox.Enabled = true;
                        }
                        break;
                    case 3:
                        {
                            ///
                            ///数据源信息
                            ///
                            //设置实例名称
                            this.severNameLabel.Text = strSeverNameLabelIntance;// "实例名称";
                            this.fileTextBox.Hide();
                            this.fileButton.Hide();
                            this.instanceTextBox.Show();

                            //数据库名称
                            this.dbNameLabel.Enabled = true;
                            this.dbNameTextBox.Enabled = true;

                            //用户名称
                            this.userLabel.Enabled = true;
                            this.userTextBox.Enabled = true;

                            //密码
                            this.passwordLabel.Enabled = true;
                            this.passwordTextBox.Enabled = true;

                            this.imageCheckBox.Checked = false;
                            this.imageCheckBox.Enabled = true;
                        }
                        break;
                    default:
                        break;
                }

                checkConnectionParametersValid();
            }
            catch (Exception ec)
            {
                MessageBox.Show(ec.Message);
            }

        }

        private void transactionCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            checkConnectionParametersValid();
        }

        private void encryptCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (0 != this.datasourceTypeComboBox.SelectedIndex)
            {
                MessageBox.Show(strErrNoUseFunction);
                return;
            }

            checkConnectionParametersValid();
        }

        private void readOnlyRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            checkConnectionParametersValid();
        }

        private void filePathChanged(object sender, EventArgs e)
        {
            checkConnectionParametersValid();
        }

        private void instanceTextChanged(object sender, EventArgs e)
        {
            checkConnectionParametersValid();
        }

        private void dbNameTextChanged(object sender, EventArgs e)
        {
            checkConnectionParametersValid();
        }

        private void userTextChanged(object sender, EventArgs e)
        {
            checkConnectionParametersValid();
        }

        private void passwordTextChanged(object sender, EventArgs e)
        {
            checkConnectionParametersValid();
        }


        [Conditional("TRACE"), Conditional("DEBUG")]
        private void DEBUG_TRACE(string strMsg)
        {

            Trace.WriteLine(strMsg);
        }


        private void fileTextBox_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            if (Keys.Tab == e.KeyCode)
            {
                fileTextBox.SelectAll();
            }
        }

        private void instanceTextBox_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            if (Keys.Tab == e.KeyCode)
            {
                instanceTextBox.SelectAll();
            }
        }

        private void dbNameTextBox_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            if (Keys.Tab == e.KeyCode)
            {
                dbNameTextBox.SelectAll();
            }
        }

        private void userTextBox_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            if (Keys.Tab == e.KeyCode)
            {
                userTextBox.SelectAll();
            }
        }

        private void passwordTextBox_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            if (Keys.Tab == e.KeyCode)
            {
                passwordTextBox.SelectAll();
            }
        }

        private void fileButton_KeyDown(object sender, KeyEventArgs e)
        {
            if (Keys.Enter == e.KeyCode)
            {
                fileButton_Click(sender, e);
            }
        }

        private void lnkHomepage_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start(strlnkHomepage);
        }

        private void lnkHelp_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start("Help/SupermapProvider.chm");
        }

        private void SuperMapConnectionControl_Load(object sender, EventArgs e)
        {

        }

        private void SuperMapLogo_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start(strlnkHomepage);
        }

    }
}