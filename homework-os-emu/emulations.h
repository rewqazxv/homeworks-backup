#ifndef EMULATIONS_H
#define EMULATIONS_H

#include <vector>
#include <memory>
#include <utility>

using std::vector;
using std::shared_ptr;
using std::pair;

typedef vector<vector<int>> blocks_log;
typedef vector<int> pages_t;

const int NOPAGE = -1;

blocks_log lru(const int blockNum, const pages_t &pages);
blocks_log fifo(const int blockNum, const pages_t &pages);
blocks_log op(const int blockNum, const pages_t &pages);

pair<double,double> missing_and_displacement(const blocks_log &log);

#endif // EMULATIONS_H
