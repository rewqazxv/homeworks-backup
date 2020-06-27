using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    class StationDao
    {
        private DB db = new DB();

        public DataTable getStations()
        {
            string sql = "select * from station";
            return db.ExecuteQuery(sql);
        }

        public void deleteStationById(int sid)
        {
            string sql = "exec delstation @sid";
            SqlParameter pSid = new SqlParameter("@sid", sid);
            db.ExecuteUpdate(sql, pSid);
        }

        public void changeName(int sid, string newname)
        {
            string sql = "update station set name=@newname where id=@sid";
            SqlParameter pNewName = new SqlParameter("@newname", newname);
            SqlParameter pSid = new SqlParameter("@sid", sid);
            db.ExecuteUpdate(sql, pNewName, pSid);
        }

        public void addStation(string name, int rid, int num)
        {
            string sql = "exec addstation @name, @rid, @num";
            SqlParameter pName = new SqlParameter("@name", name);
            SqlParameter pRid = new SqlParameter("@rid", rid);
            SqlParameter pNum = new SqlParameter("@num", num);
            db.ExecuteUpdate(sql, pName, pRid, pNum);
        }
    }

    class RouteDao
    {
        private DB db = new DB();

        public DataTable getRoutes()
        {
            string sql = "select * from route";
            return db.ExecuteQuery(sql);
        }

        public DataRow getRouteById(int id)
        {
            string sql = "select * from route where id=@id";
            SqlParameter pId = new SqlParameter("@id", id);
            DataTable data = db.ExecuteQuery(sql, pId);
            return data.Rows[0];
        }

        public DataTable getRouteDetail(int rid)
        {
            string sql = "select num,sid,name from via,station where via.sid=station.id and rid=@rid order by num";
            SqlParameter pRid = new SqlParameter("@rid", rid);
            return db.ExecuteQuery(sql, pRid);
        }

        public DataTable getMap()
        {
            string sql = "select * from map order by route_id, num asc";
            return db.ExecuteQuery(sql);
        }

        public void addRoute(string name, string first, string last, int price)
        {
            string sql = "insert into route(name,first,last,price) values (@name,@first,@last,@price)";
            SqlParameter pNname = new SqlParameter("@name", name);
            SqlParameter pFirst = new SqlParameter("@first", first);
            SqlParameter pLast = new SqlParameter("@last", last);
            SqlParameter pPrice = new SqlParameter("@price", price);
            db.ExecuteUpdate(sql, pNname, pFirst, pLast, pPrice);
        }

        public void change(int rid, string name, string first, string last, int price)
        {
            string sql = "update route set name=@name, first=@first, last=@last, price=@price where id=@rid";
            SqlParameter pNewName = new SqlParameter("@name", name);
            SqlParameter pRid = new SqlParameter("@rid", rid);
            SqlParameter pFirst = new SqlParameter("@first", first);
            SqlParameter pLast = new SqlParameter("@last", last);
            SqlParameter pPrice = new SqlParameter("@price", price);
            db.ExecuteUpdate(sql, pNewName, pRid, pFirst, pLast, pPrice);
        }

        public void deleteRouteById(int rid)
        {
            string sql = "delete from via where rid=@rid";
            SqlParameter pRid = new SqlParameter("@rid", rid);
            db.ExecuteUpdate(sql, pRid);
            sql = "delete from route where id=@rid";
            pRid = new SqlParameter("@rid", rid);
            db.ExecuteUpdate(sql, pRid);
        }
    }
}
