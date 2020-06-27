using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Microsoft.VisualBasic;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        private RouteDao routeDao = new RouteDao();
        private StationDao stationDao = new StationDao();

        public Form1()
        {
            InitializeComponent();
        }

        private void updateRouteDetail()
        {
            object val = comboBoxRoute.SelectedValue;
            if (val != null)
            {
                int rid = (int)val;
                dataGridViewRouteDetail.DataSource = routeDao.getRouteDetail(rid);
                var route = routeDao.getRouteById(rid);
                labelRoute.Text = "首班车" + route["first"].ToString().Trim() + " 末班车" + route["last"].ToString().Trim() + " 票价" + route["price"].ToString().Trim() + "元";
            }
            else
            {
                dataGridViewRouteDetail.DataSource = null;
                labelRoute.Text = "";
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            routeTableAdapter.Fill(this.busmapDataSet.route);
            stationTableAdapter.Fill(this.busmapDataSet.station);
            updateRouteDetail();
        }

        private void comboBoxRoute_SelectedIndexChanged(object sender, EventArgs e)
        {
            updateRouteDetail();
        }

        private void buttonRouteChange_Click(object sender, EventArgs e)
        {
            object val = comboBoxRoute.SelectedValue;
            if (val == null) return;
            int rid = (int)val;
            var data = routeDao.getRouteById(rid);

            string name = Interaction.InputBox("输入新名称", "修改线路", data["name"].ToString().Trim()).Trim();
            string first = Interaction.InputBox("首班车", "修改线路", data["first"].ToString().Trim()).Trim();
            string last = Interaction.InputBox("末班车", "修改线路", data["last"].ToString().Trim()).Trim();
            int price = Int32.Parse(Interaction.InputBox("价格", "修改线路", data["price"].ToString().Trim()).Trim());

            if (name != null && name.Length > 0)
            {
                routeDao.change(rid, name, first, last, price);
                routeTableAdapter.Fill(this.busmapDataSet.route);
                updateRouteDetail();
            }
        }

        private void buttonAddRoute_Click(object sender, EventArgs e)
        {
            string name = Interaction.InputBox("输入线路名称", "新增线路").Trim();
            string first = Interaction.InputBox("首班车", "新增线路").Trim();
            string last = Interaction.InputBox("末班车", "新增线路").Trim();
            int price = Int32.Parse(Interaction.InputBox("价格", "新增线路").Trim());
            if (name.Length > 0)
            {
                routeDao.addRoute(name, first, last, price);
                routeTableAdapter.Fill(this.busmapDataSet.route);
            }
        }

        private void buttonRouteDelete_Click(object sender, EventArgs e)
        {
            var confirmResult = MessageBox.Show("确定删除线路吗", "删除确认", MessageBoxButtons.YesNo);
            object val = comboBoxRoute.SelectedValue;
            if (val != null && confirmResult == DialogResult.Yes)
            {
                int rid = (int)val;
                routeDao.deleteRouteById(rid);
                routeTableAdapter.Fill(this.busmapDataSet.route);
                stationTableAdapter.Fill(this.busmapDataSet.station);
                updateRouteDetail();
            }
        }

        private void buttonStationChange_Click(object sender, EventArgs e)
        {
            int sid = Int32.Parse(dataGridViewStationDetail.CurrentRow.Cells[0].Value.ToString());
            string newname = Interaction.InputBox("输入新名称", "更改站点名").Trim();
            if (newname != null && newname.Length > 0)
            {
                stationDao.changeName(sid, newname);
                stationTableAdapter.Fill(this.busmapDataSet.station);
                updateRouteDetail();
            }
        }

        private void buttonStationDelete_Click(object sender, EventArgs e)
        {
            var confirmResult = MessageBox.Show("确定删除站点吗", "删除确认", MessageBoxButtons.YesNo);
            if (confirmResult == DialogResult.Yes)
            {
                int sid = Int32.Parse(dataGridViewStationDetail.CurrentRow.Cells[0].Value.ToString());
                stationDao.deleteStationById(sid);
                stationTableAdapter.Fill(this.busmapDataSet.station);
                routeTableAdapter.Fill(this.busmapDataSet.route);
                updateRouteDetail();
            }
        }

        private void buttonRouteAddStation_Click(object sender, EventArgs e)
        {
            string name = Interaction.InputBox("输入站点名称", "新增站点").Trim();
            object val = comboBoxRoute.SelectedValue;
            if (val != null && name.Length > 0)
            {
                var numobj = dataGridViewRouteDetail.CurrentRow;
                int num = numobj == null ? 1 : Int32.Parse(numobj.Cells[0].Value.ToString()) + 1;
                int rid = (int)val;
                stationDao.addStation(name, rid, num);
                updateRouteDetail();
                stationTableAdapter.Fill(this.busmapDataSet.station);
            }
        }

        private void buttonRouteDeleteStation_Click(object sender, EventArgs e)
        {
            var confirmResult = MessageBox.Show("确定删除站点吗", "删除确认", MessageBoxButtons.YesNo);
            if (confirmResult == DialogResult.Yes)
            {
                int sid = Int32.Parse(dataGridViewRouteDetail.CurrentRow.Cells[1].Value.ToString());
                stationDao.deleteStationById(sid);
                stationTableAdapter.Fill(this.busmapDataSet.station);
                routeTableAdapter.Fill(this.busmapDataSet.route);
                updateRouteDetail();
            }
        }

        private void buttonCalcSp_Click(object sender, EventArgs e)
        {
            try
            {
                int from = (int)comboBoxFrom.SelectedValue;
                int to = (int)comboBoxTo.SelectedValue;
                var bfs = new BFS(from, to);
                var res = bfs.Result();
                var str = new StringBuilder();
                str.Append("乘坐" + bfs.GetRouteNameByRid(res[0].rid));
                for (int i = 1; i < res.Count; i++)
                    if (res[i - 1].rid != res[i].rid)
                        str.Append("，" + Environment.NewLine + "在" + bfs.GetStationNameBySid(res[i - 1].to) + "换乘" + bfs.GetRouteNameByRid(res[i].rid));
                str.Append("，" + Environment.NewLine + "到达目的地" + bfs.GetStationNameBySid(res.Last().to) + "。");
                textBox1.Text = str.ToString();
            }
            catch (NullReferenceException)
            {
                textBox1.Text = "";
            }
            catch (ZeroLengthException)
            {
                textBox1.Text = "原地踏步";
            }
            catch (NoRouteException)
            {
                textBox1.Text = "走投无路";
            }
        }
    }
}
