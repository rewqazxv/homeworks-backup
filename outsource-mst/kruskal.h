#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "pch.hpp"
using namespace std;

#include "mst.h"
#include "edge.h"

class Kruskal: public Mst {
public:
    Kruskal(const vector<edge> &edges);
};

#endif // KRUSKAL_H
