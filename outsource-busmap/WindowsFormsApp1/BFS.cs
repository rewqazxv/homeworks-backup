using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace System.Collections.Generic
{
    public static class MehtondExtension
    {
        public static TValue GetOrCreate<TKey, TValue>(this IDictionary<TKey, TValue> dict, TKey key) where TValue : new()
        {
            TValue val;

            if (!dict.TryGetValue(key, out val))
            {
                val = new TValue();
                dict.Add(key, val);
            }

            return val;
        }
    }
}

namespace WindowsFormsApp1
{
    class Edge
    {
        public int to;
        public int rid;

        public Edge(int to, int rid)
        {
            this.to = to;
            this.rid = rid;
        }
    }

    class Point
    {
        public int sid, pre;

        public Point(int sid, int pre)
        {
            this.sid = sid;
            this.pre = pre;
        }
    }

    class NoRouteException : Exception { }
    class ZeroLengthException : Exception { }

    class BFS
    {
        private List<Edge> result = new List<Edge>();
        private Dictionary<int, HashSet<Edge>> path = new Dictionary<int, HashSet<Edge>>();
        private Dictionary<int, string> ridToName = new Dictionary<int, string>();
        private Dictionary<int, string> sidToName = new Dictionary<int, string>();

        public BFS(int from, int to)
        {
            if (from == to)
                throw new ZeroLengthException();
            RouteDao routeDao = new RouteDao();
            StationDao stationDao = new StationDao();

            var routes = routeDao.getRoutes();
            foreach (DataRow row in routes.Rows)
            {
                ridToName[Int32.Parse(row["id"].ToString())] = row["name"].ToString().Trim();
            }

            var stations = stationDao.getStations();
            foreach (DataRow row in stations.Rows)
            {
                sidToName[Int32.Parse(row["id"].ToString())] = row["name"].ToString().Trim();
            }

            var rawMap = routeDao.getMap();
            for (int i = 0; i < rawMap.Rows.Count; i++)
            {
                var row = rawMap.Rows[i];
                try
                {
                    var pre = rawMap.Rows[i - 1];
                    if (Int32.Parse(pre["route_id"].ToString()) == Int32.Parse(row["route_id"].ToString()) && Int32.Parse(pre["num"].ToString()) == Int32.Parse(row["num"].ToString()) - 1)
                        path.GetOrCreate(Int32.Parse(row["station_id"].ToString())).Add(new Edge(Int32.Parse(pre["station_id"].ToString()), Int32.Parse(row["route_id"].ToString())));
                }
                catch (IndexOutOfRangeException) {; }
                try
                {
                    var next = rawMap.Rows[i + 1];
                    if (Int32.Parse(next["route_id"].ToString()) == Int32.Parse(row["route_id"].ToString()) && Int32.Parse(next["num"].ToString()) == Int32.Parse(row["num"].ToString()) + 1)
                        path.GetOrCreate(Int32.Parse(row["station_id"].ToString())).Add(new Edge(Int32.Parse(next["station_id"].ToString()), Int32.Parse(row["route_id"].ToString())));
                }
                catch (IndexOutOfRangeException) {; }
            }

            Calc(from, to);
        }

        void Calc(int from, int to)
        {
            Dictionary<int, int> visited = new Dictionary<int, int>();
            LinkedList<Point> queue = new LinkedList<Point>();
            queue.AddLast(new Point(from, from));
            while (queue.Count > 0)
            {
                var p = queue.First();
                queue.RemoveFirst();
                if (p.sid == to)
                {
                    List<int> seq = new List<int>();
                    for (int cur = p.sid, pre = p.pre; cur != pre; cur = pre, pre = visited[pre])
                        seq.Add(cur);
                    seq.Add(from);
                    seq.Reverse();
                    for (int i = 1; i < seq.Count; i++)
                        result.Add(new Edge(seq[i], whichRoute(seq[i - 1], seq[i])));
                    return;
                }
                visited[p.sid] = p.pre;
                foreach (var i in path[p.sid])
                    if (!visited.ContainsKey(i.to))
                        queue.AddLast(new Point(i.to, p.sid));
            }
            throw new NoRouteException();
        }

        int whichRoute(int from, int to)
        {
            foreach (var i in path[from])
                if (i.to == to)
                    return i.rid;
            throw new Exception(String.Format("no such route: from {0} to {1}", from, to));
        }

        public List<Edge> Result()
        {
            if (result.Count == 0) throw new ZeroLengthException();
            return result;
        }

        public string GetRouteNameByRid(int rid)
        {
            return ridToName[rid];
        }

        public string GetStationNameBySid(int sid)
        {
            return sidToName[sid];
        }
    }
}
