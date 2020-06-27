#ifndef PRIM_H
#define PRIM_H

#include "pch.hpp"
using namespace std;

#include "mst.h"
#include "edge.h"

class Prim: public Mst {
public:
    Prim(const vector<edge> &edges);
};

#endif // PRIM_H
