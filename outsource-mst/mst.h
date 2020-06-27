#ifndef MST_H
#define MST_H

#include "pch.hpp"
using namespace std;

#include "edge.h"

class Mst {
public:
    virtual ~Mst() {}

    const vector<edge> &result() {
        return res;
    }
    int sumweight() {
        return accumulate(res.begin(), res.end(), 0, [](int sum, const edge & e) {
            return sum + e.w;
        });
    }
    int sumdistance() {
        return accumulate(res.begin(), res.end(), 0, [](int sum, const edge & e) {
            return sum + e.d;
        });
    }

protected:
    Mst() = default;
    vector<edge> res;
    int getV(const vector<edge> &edges) {
        set<int> cnt;
        for (auto i : edges) {
            cnt.insert(i.s);
            cnt.insert(i.t);
        }
        return cnt.size();
    }
};

#endif // MST_H
