using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.SqlClient;
using System.Threading.Tasks;
using System.Configuration;

namespace WindowsFormsApp1
{
    class DB
    {
        private string MySqlCon = ConfigurationManager.ConnectionStrings["WindowsFormsApp1.Properties.Settings.busmapConnectionString"].ConnectionString;

        public DataTable ExecuteQuery(string sqlStr, params SqlParameter[] parameters) // 用于查询
        {
            SqlConnection con = new SqlConnection(MySqlCon);
            con.Open();
            SqlCommand cmd = new SqlCommand();
            cmd.Connection = con;
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = sqlStr;
            foreach (SqlParameter i in parameters)
                cmd.Parameters.Add(i);
            DataTable dt = new DataTable();
            SqlDataAdapter msda = new SqlDataAdapter(cmd);
            msda.Fill(dt);
            con.Close();
            return dt;
        }

        public int ExecuteUpdate(string sqlStr, params SqlParameter[] parameters) // 用于增删改;
        {
            SqlConnection con = new SqlConnection(@MySqlCon);
            con.Open();
            SqlCommand cmd = new SqlCommand();
            cmd.Connection = con;
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = sqlStr;
            foreach (SqlParameter i in parameters)
                cmd.Parameters.Add(i);
            int iud = 0;
            iud = cmd.ExecuteNonQuery();
            con.Close();
            return iud;
        }
    }
}
