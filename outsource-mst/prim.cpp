#include "prim.h"

static edge none{-1, -1, 1000000, 0};

Prim::Prim(const vector<edge> &es) {
    int V = getV(es);
    vector<vector<edge>> m(V, vector<edge>(V, none));
    for (const auto &i : es) {
        m[i.s][i.t] = min(m[i.s][i.t], i);
        m[i.t][i.s] = min(m[i.t][i.s], i);
    }
    vector<edge> minEdge(V, none);
    vector<bool> used(V, false);

    used[0] = true;
    for (int i = 0; i < V; i++)
        minEdge[i] = min(minEdge[i], m[0][i]);

    for (;;) {
        int s = -1;
        for (int i = 0; i < V; i++)
            if (!used[i] && minEdge[i].s != -1 && (s == -1 || minEdge[i] < minEdge[s])) s = i;
        if (s == -1) break;
        used[s] = true;
        res.push_back(minEdge[s]);
        for (int i = 0; i < V; i++) {
            minEdge[i] = min(minEdge[i], m[s][i]);
        }
    }
}
