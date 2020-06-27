#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include "pch.hpp"
using namespace std;

class disjoint_set {
    vector<size_t> parent;
    vector<int> rank;
    int groups;

public:
    disjoint_set(int n): parent(n), rank(n, 0), groups(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    void unite(size_t x, size_t y) {
        x = root(x);
        y = root(y);
        if (x == y) return;

        --groups;
        if (rank[x] < rank[y])
            parent[x] = y;
        else {
            parent[y] = x;
            if (rank[x] == rank[y]) ++rank[x];
        }
    }

    size_t root(size_t x) {
        if (parent[x] != x)
            parent[x] = root(parent[x]);
        return parent[x];
    }

    bool same(size_t x, size_t y) {
        return root(x) == root(y);
    }

    int count() {
        return groups;
    }
};

#endif // DISJOINT_SET_H
