#include "kruskal.h"
#include "disjoint_set.h"

Kruskal::Kruskal(const vector<edge> &es) {
    vector<edge> edges = es;
    sort(edges.begin(), edges.end());
    disjoint_set ds(getV(edges));
    for (const auto &i : edges) {
        if (!ds.same(i.s, i.t)) {
            ds.unite(i.s, i.t);
            res.push_back(i);
        }
    }
}
