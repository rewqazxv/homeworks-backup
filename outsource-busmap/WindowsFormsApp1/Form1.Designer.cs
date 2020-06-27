namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.labelRoute = new System.Windows.Forms.Label();
            this.buttonAddRoute = new System.Windows.Forms.Button();
            this.buttonRouteChange = new System.Windows.Forms.Button();
            this.buttonRouteDelete = new System.Windows.Forms.Button();
            this.buttonRouteAddStation = new System.Windows.Forms.Button();
            this.buttonRouteDeleteStation = new System.Windows.Forms.Button();
            this.comboBoxRoute = new System.Windows.Forms.ComboBox();
            this.routeBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.busmapDataSet = new WindowsFormsApp1.busmapDataSet();
            this.dataGridViewRouteDetail = new System.Windows.Forms.DataGridView();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.splitContainer2 = new System.Windows.Forms.SplitContainer();
            this.buttonStationChangeName = new System.Windows.Forms.Button();
            this.buttonStationDelete = new System.Windows.Forms.Button();
            this.dataGridViewStationDetail = new System.Windows.Forms.DataGridView();
            this.idDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.nameDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.stationBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.splitContainer3 = new System.Windows.Forms.SplitContainer();
            this.comboBoxTo = new System.Windows.Forms.ComboBox();
            this.stationBindingSourceTo = new System.Windows.Forms.BindingSource(this.components);
            this.buttonCalcSp = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.comboBoxFrom = new System.Windows.Forms.ComboBox();
            this.stationBindingSourceFrom = new System.Windows.Forms.BindingSource(this.components);
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.stationTableAdapter = new WindowsFormsApp1.busmapDataSetTableAdapters.stationTableAdapter();
            this.routeTableAdapter = new WindowsFormsApp1.busmapDataSetTableAdapters.routeTableAdapter();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.routeBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.busmapDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewRouteDetail)).BeginInit();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer2)).BeginInit();
            this.splitContainer2.Panel1.SuspendLayout();
            this.splitContainer2.Panel2.SuspendLayout();
            this.splitContainer2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewStationDetail)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.stationBindingSource)).BeginInit();
            this.tabPage3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer3)).BeginInit();
            this.splitContainer3.Panel1.SuspendLayout();
            this.splitContainer3.Panel2.SuspendLayout();
            this.splitContainer3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.stationBindingSourceTo)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.stationBindingSourceFrom)).BeginInit();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl1.Location = new System.Drawing.Point(0, 0);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(830, 478);
            this.tabControl1.TabIndex = 1;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.splitContainer1);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(822, 452);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "线路";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(3, 3);
            this.splitContainer1.Name = "splitContainer1";
            this.splitContainer1.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.labelRoute);
            this.splitContainer1.Panel1.Controls.Add(this.buttonAddRoute);
            this.splitContainer1.Panel1.Controls.Add(this.buttonRouteChange);
            this.splitContainer1.Panel1.Controls.Add(this.buttonRouteDelete);
            this.splitContainer1.Panel1.Controls.Add(this.buttonRouteAddStation);
            this.splitContainer1.Panel1.Controls.Add(this.buttonRouteDeleteStation);
            this.splitContainer1.Panel1.Controls.Add(this.comboBoxRoute);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.dataGridViewRouteDetail);
            this.splitContainer1.Size = new System.Drawing.Size(816, 446);
            this.splitContainer1.SplitterDistance = 25;
            this.splitContainer1.TabIndex = 3;
            // 
            // labelRoute
            // 
            this.labelRoute.AutoSize = true;
            this.labelRoute.Dock = System.Windows.Forms.DockStyle.Left;
            this.labelRoute.Location = new System.Drawing.Point(145, 0);
            this.labelRoute.Name = "labelRoute";
            this.labelRoute.Size = new System.Drawing.Size(0, 12);
            this.labelRoute.TabIndex = 8;
            // 
            // buttonAddRoute
            // 
            this.buttonAddRoute.Dock = System.Windows.Forms.DockStyle.Right;
            this.buttonAddRoute.Location = new System.Drawing.Point(441, 0);
            this.buttonAddRoute.Name = "buttonAddRoute";
            this.buttonAddRoute.Size = new System.Drawing.Size(75, 25);
            this.buttonAddRoute.TabIndex = 7;
            this.buttonAddRoute.Text = "新增线路";
            this.buttonAddRoute.UseVisualStyleBackColor = true;
            this.buttonAddRoute.Click += new System.EventHandler(this.buttonAddRoute_Click);
            // 
            // buttonRouteChange
            // 
            this.buttonRouteChange.Dock = System.Windows.Forms.DockStyle.Right;
            this.buttonRouteChange.Location = new System.Drawing.Point(516, 0);
            this.buttonRouteChange.Name = "buttonRouteChange";
            this.buttonRouteChange.Size = new System.Drawing.Size(75, 25);
            this.buttonRouteChange.TabIndex = 6;
            this.buttonRouteChange.Text = "修改";
            this.buttonRouteChange.UseVisualStyleBackColor = true;
            this.buttonRouteChange.Click += new System.EventHandler(this.buttonRouteChange_Click);
            // 
            // buttonRouteDelete
            // 
            this.buttonRouteDelete.Dock = System.Windows.Forms.DockStyle.Right;
            this.buttonRouteDelete.Location = new System.Drawing.Point(591, 0);
            this.buttonRouteDelete.Name = "buttonRouteDelete";
            this.buttonRouteDelete.Size = new System.Drawing.Size(75, 25);
            this.buttonRouteDelete.TabIndex = 5;
            this.buttonRouteDelete.Text = "删除";
            this.buttonRouteDelete.UseVisualStyleBackColor = true;
            this.buttonRouteDelete.Click += new System.EventHandler(this.buttonRouteDelete_Click);
            // 
            // buttonRouteAddStation
            // 
            this.buttonRouteAddStation.Dock = System.Windows.Forms.DockStyle.Right;
            this.buttonRouteAddStation.Location = new System.Drawing.Point(666, 0);
            this.buttonRouteAddStation.Name = "buttonRouteAddStation";
            this.buttonRouteAddStation.Size = new System.Drawing.Size(75, 25);
            this.buttonRouteAddStation.TabIndex = 4;
            this.buttonRouteAddStation.Text = "新增站点";
            this.buttonRouteAddStation.UseVisualStyleBackColor = true;
            this.buttonRouteAddStation.Click += new System.EventHandler(this.buttonRouteAddStation_Click);
            // 
            // buttonRouteDeleteStation
            // 
            this.buttonRouteDeleteStation.Dock = System.Windows.Forms.DockStyle.Right;
            this.buttonRouteDeleteStation.Location = new System.Drawing.Point(741, 0);
            this.buttonRouteDeleteStation.Name = "buttonRouteDeleteStation";
            this.buttonRouteDeleteStation.Size = new System.Drawing.Size(75, 25);
            this.buttonRouteDeleteStation.TabIndex = 3;
            this.buttonRouteDeleteStation.Text = "删除站点";
            this.buttonRouteDeleteStation.UseVisualStyleBackColor = true;
            this.buttonRouteDeleteStation.Click += new System.EventHandler(this.buttonRouteDeleteStation_Click);
            // 
            // comboBoxRoute
            // 
            this.comboBoxRoute.DataSource = this.routeBindingSource;
            this.comboBoxRoute.DisplayMember = "name";
            this.comboBoxRoute.Dock = System.Windows.Forms.DockStyle.Left;
            this.comboBoxRoute.FormattingEnabled = true;
            this.comboBoxRoute.Location = new System.Drawing.Point(0, 0);
            this.comboBoxRoute.Name = "comboBoxRoute";
            this.comboBoxRoute.Size = new System.Drawing.Size(145, 20);
            this.comboBoxRoute.TabIndex = 2;
            this.comboBoxRoute.ValueMember = "id";
            this.comboBoxRoute.SelectedIndexChanged += new System.EventHandler(this.comboBoxRoute_SelectedIndexChanged);
            // 
            // routeBindingSource
            // 
            this.routeBindingSource.DataMember = "route";
            this.routeBindingSource.DataSource = this.busmapDataSet;
            // 
            // busmapDataSet
            // 
            this.busmapDataSet.DataSetName = "busmapDataSet";
            this.busmapDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // dataGridViewRouteDetail
            // 
            this.dataGridViewRouteDetail.AllowUserToAddRows = false;
            this.dataGridViewRouteDetail.AllowUserToDeleteRows = false;
            this.dataGridViewRouteDetail.AllowUserToResizeRows = false;
            this.dataGridViewRouteDetail.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewRouteDetail.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dataGridViewRouteDetail.Location = new System.Drawing.Point(0, 0);
            this.dataGridViewRouteDetail.MultiSelect = false;
            this.dataGridViewRouteDetail.Name = "dataGridViewRouteDetail";
            this.dataGridViewRouteDetail.ReadOnly = true;
            this.dataGridViewRouteDetail.RowTemplate.Height = 23;
            this.dataGridViewRouteDetail.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridViewRouteDetail.Size = new System.Drawing.Size(816, 417);
            this.dataGridViewRouteDetail.TabIndex = 2;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.splitContainer2);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(822, 452);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "公交站";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // splitContainer2
            // 
            this.splitContainer2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer2.Location = new System.Drawing.Point(3, 3);
            this.splitContainer2.Name = "splitContainer2";
            this.splitContainer2.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer2.Panel1
            // 
            this.splitContainer2.Panel1.Controls.Add(this.buttonStationChangeName);
            this.splitContainer2.Panel1.Controls.Add(this.buttonStationDelete);
            // 
            // splitContainer2.Panel2
            // 
            this.splitContainer2.Panel2.Controls.Add(this.dataGridViewStationDetail);
            this.splitContainer2.Size = new System.Drawing.Size(816, 446);
            this.splitContainer2.SplitterDistance = 25;
            this.splitContainer2.TabIndex = 1;
            // 
            // buttonStationChangeName
            // 
            this.buttonStationChangeName.Dock = System.Windows.Forms.DockStyle.Right;
            this.buttonStationChangeName.Location = new System.Drawing.Point(666, 0);
            this.buttonStationChangeName.Name = "buttonStationChangeName";
            this.buttonStationChangeName.Size = new System.Drawing.Size(75, 25);
            this.buttonStationChangeName.TabIndex = 1;
            this.buttonStationChangeName.Text = "改名";
            this.buttonStationChangeName.UseVisualStyleBackColor = true;
            // 
            // buttonStationDelete
            // 
            this.buttonStationDelete.Dock = System.Windows.Forms.DockStyle.Right;
            this.buttonStationDelete.Location = new System.Drawing.Point(741, 0);
            this.buttonStationDelete.Name = "buttonStationDelete";
            this.buttonStationDelete.Size = new System.Drawing.Size(75, 25);
            this.buttonStationDelete.TabIndex = 0;
            this.buttonStationDelete.Text = "删除";
            this.buttonStationDelete.UseVisualStyleBackColor = true;
            this.buttonStationDelete.Click += new System.EventHandler(this.buttonStationDelete_Click);
            // 
            // dataGridViewStationDetail
            // 
            this.dataGridViewStationDetail.AllowUserToAddRows = false;
            this.dataGridViewStationDetail.AllowUserToDeleteRows = false;
            this.dataGridViewStationDetail.AllowUserToResizeRows = false;
            this.dataGridViewStationDetail.AutoGenerateColumns = false;
            this.dataGridViewStationDetail.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewStationDetail.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.idDataGridViewTextBoxColumn,
            this.nameDataGridViewTextBoxColumn});
            this.dataGridViewStationDetail.DataSource = this.stationBindingSource;
            this.dataGridViewStationDetail.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dataGridViewStationDetail.Location = new System.Drawing.Point(0, 0);
            this.dataGridViewStationDetail.MultiSelect = false;
            this.dataGridViewStationDetail.Name = "dataGridViewStationDetail";
            this.dataGridViewStationDetail.ReadOnly = true;
            this.dataGridViewStationDetail.RowTemplate.Height = 23;
            this.dataGridViewStationDetail.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridViewStationDetail.Size = new System.Drawing.Size(816, 417);
            this.dataGridViewStationDetail.TabIndex = 0;
            // 
            // idDataGridViewTextBoxColumn
            // 
            this.idDataGridViewTextBoxColumn.DataPropertyName = "id";
            this.idDataGridViewTextBoxColumn.HeaderText = "id";
            this.idDataGridViewTextBoxColumn.Name = "idDataGridViewTextBoxColumn";
            this.idDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // nameDataGridViewTextBoxColumn
            // 
            this.nameDataGridViewTextBoxColumn.DataPropertyName = "name";
            this.nameDataGridViewTextBoxColumn.HeaderText = "name";
            this.nameDataGridViewTextBoxColumn.Name = "nameDataGridViewTextBoxColumn";
            this.nameDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // stationBindingSource
            // 
            this.stationBindingSource.DataMember = "station";
            this.stationBindingSource.DataSource = this.busmapDataSet;
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.splitContainer3);
            this.tabPage3.Location = new System.Drawing.Point(4, 22);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(822, 452);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "换乘查询";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // splitContainer3
            // 
            this.splitContainer3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer3.Location = new System.Drawing.Point(3, 3);
            this.splitContainer3.Name = "splitContainer3";
            this.splitContainer3.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer3.Panel1
            // 
            this.splitContainer3.Panel1.Controls.Add(this.comboBoxTo);
            this.splitContainer3.Panel1.Controls.Add(this.buttonCalcSp);
            this.splitContainer3.Panel1.Controls.Add(this.label3);
            this.splitContainer3.Panel1.Controls.Add(this.comboBoxFrom);
            // 
            // splitContainer3.Panel2
            // 
            this.splitContainer3.Panel2.Controls.Add(this.textBox1);
            this.splitContainer3.Size = new System.Drawing.Size(816, 446);
            this.splitContainer3.SplitterDistance = 25;
            this.splitContainer3.TabIndex = 5;
            // 
            // comboBoxTo
            // 
            this.comboBoxTo.DataSource = this.stationBindingSourceTo;
            this.comboBoxTo.DisplayMember = "name";
            this.comboBoxTo.Dock = System.Windows.Forms.DockStyle.Left;
            this.comboBoxTo.FormattingEnabled = true;
            this.comboBoxTo.Location = new System.Drawing.Point(138, 0);
            this.comboBoxTo.Name = "comboBoxTo";
            this.comboBoxTo.Size = new System.Drawing.Size(121, 20);
            this.comboBoxTo.TabIndex = 0;
            this.comboBoxTo.ValueMember = "id";
            // 
            // stationBindingSourceTo
            // 
            this.stationBindingSourceTo.DataMember = "station";
            this.stationBindingSourceTo.DataSource = this.busmapDataSet;
            // 
            // buttonCalcSp
            // 
            this.buttonCalcSp.Dock = System.Windows.Forms.DockStyle.Right;
            this.buttonCalcSp.Location = new System.Drawing.Point(741, 0);
            this.buttonCalcSp.Name = "buttonCalcSp";
            this.buttonCalcSp.Size = new System.Drawing.Size(75, 25);
            this.buttonCalcSp.TabIndex = 3;
            this.buttonCalcSp.Text = "计算";
            this.buttonCalcSp.UseVisualStyleBackColor = true;
            this.buttonCalcSp.Click += new System.EventHandler(this.buttonCalcSp_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Dock = System.Windows.Forms.DockStyle.Left;
            this.label3.Location = new System.Drawing.Point(121, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(17, 12);
            this.label3.TabIndex = 2;
            this.label3.Text = "->";
            // 
            // comboBoxFrom
            // 
            this.comboBoxFrom.DataSource = this.stationBindingSourceFrom;
            this.comboBoxFrom.DisplayMember = "name";
            this.comboBoxFrom.Dock = System.Windows.Forms.DockStyle.Left;
            this.comboBoxFrom.FormattingEnabled = true;
            this.comboBoxFrom.Location = new System.Drawing.Point(0, 0);
            this.comboBoxFrom.Name = "comboBoxFrom";
            this.comboBoxFrom.Size = new System.Drawing.Size(121, 20);
            this.comboBoxFrom.TabIndex = 1;
            this.comboBoxFrom.ValueMember = "id";
            // 
            // stationBindingSourceFrom
            // 
            this.stationBindingSourceFrom.DataMember = "station";
            this.stationBindingSourceFrom.DataSource = this.busmapDataSet;
            // 
            // textBox1
            // 
            this.textBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.textBox1.Location = new System.Drawing.Point(0, 0);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(816, 417);
            this.textBox1.TabIndex = 4;
            // 
            // stationTableAdapter
            // 
            this.stationTableAdapter.ClearBeforeFill = true;
            // 
            // routeTableAdapter
            // 
            this.routeTableAdapter.ClearBeforeFill = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(830, 478);
            this.Controls.Add(this.tabControl1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel1.PerformLayout();
            this.splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.routeBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.busmapDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewRouteDetail)).EndInit();
            this.tabPage2.ResumeLayout(false);
            this.splitContainer2.Panel1.ResumeLayout(false);
            this.splitContainer2.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer2)).EndInit();
            this.splitContainer2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewStationDetail)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.stationBindingSource)).EndInit();
            this.tabPage3.ResumeLayout(false);
            this.splitContainer3.Panel1.ResumeLayout(false);
            this.splitContainer3.Panel1.PerformLayout();
            this.splitContainer3.Panel2.ResumeLayout(false);
            this.splitContainer3.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer3)).EndInit();
            this.splitContainer3.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.stationBindingSourceTo)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.stationBindingSourceFrom)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.DataGridView dataGridViewRouteDetail;
        private System.Windows.Forms.SplitContainer splitContainer2;
        private System.Windows.Forms.DataGridView dataGridViewStationDetail;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.SplitContainer splitContainer3;
        private System.Windows.Forms.ComboBox comboBoxTo;
        private System.Windows.Forms.Button buttonCalcSp;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox comboBoxFrom;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.ComboBox comboBoxRoute;
        private System.Windows.Forms.Button buttonRouteChange;
        private System.Windows.Forms.Button buttonRouteDelete;
        private System.Windows.Forms.Button buttonRouteAddStation;
        private System.Windows.Forms.Button buttonRouteDeleteStation;
        private System.Windows.Forms.Button buttonAddRoute;
        private System.Windows.Forms.Button buttonStationChangeName;
        private System.Windows.Forms.Button buttonStationDelete;
        private busmapDataSet busmapDataSet;
        private System.Windows.Forms.BindingSource stationBindingSource;
        private busmapDataSetTableAdapters.stationTableAdapter stationTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn idDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn nameDataGridViewTextBoxColumn;
        private System.Windows.Forms.BindingSource routeBindingSource;
        private busmapDataSetTableAdapters.routeTableAdapter routeTableAdapter;
        private System.Windows.Forms.BindingSource stationBindingSourceTo;
        private System.Windows.Forms.BindingSource stationBindingSourceFrom;
        private System.Windows.Forms.Label labelRoute;
    }
}

