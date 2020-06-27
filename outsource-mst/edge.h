#ifndef EDGE_H
#define EDGE_H

struct edge {
    int s, t, d, w;
    edge(int s, int t, int d, int w): s(s), t(t), d(d), w(w) {}
    bool operator<(const edge &other) const {
        return this->d < other.d;
    }
};

#endif // EDGE_H
