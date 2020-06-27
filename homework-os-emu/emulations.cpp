#include "emulations.h"
#include <algorithm>
#include <unordered_map>
#include <utility>
using namespace std;

#include <climits>
const int INF = INT_MAX;

blocks_log fifo(const int blockNum, const pages_t &pages) {
    blocks_log result;
    vector<int> now(blockNum, NOPAGE);
    int id = 0;
    for (const auto &pageNum : pages) {
        if (std::find(now.begin(), now.end(), pageNum) == now.end()) {  //not find -> insert next
            now[id] = pageNum;
            id = (id + 1) % blockNum;
        }
        result.push_back(now);
    }
    return result;
}

blocks_log op_and_lru(const int blockNum, const vector<int> &pages, bool isOp, vector<int> *next = nullptr) {
    blocks_log result;
    vector<pair<int, int>> now(blockNum, std::make_pair(NOPAGE, INF)); //first -> pageNum, second -> nextId / preId
    vector<int> tmp(blockNum);

    for (int id = 0; id < (int)pages.size(); id++) {
        int insertId = -1, infinite = (isOp ? -1 : 1) * INF, time = isOp ? (*next)[id] : id;  //infinite -> maxNext / minPre, time -> secondData
        for (int i = 0; i < (int)now.size(); i++) {
            if (now[i].first == pages[id]) {  //exist -> update nextId
                now[i].second = time;
                insertId = -2;
                break;
            }
            if (now[i].first == NOPAGE) { //noPage -> insert
                now[i] = std::make_pair(pages[id], time);
                insertId = -2;
                break;
            }
        }
        if (insertId == -1) {    //else -> find maxNext / minPre
            for (int i = 0; i < (int)now.size(); i++) {
                if ((isOp && now[i].second > infinite) || (!isOp && now[i].second < infinite)) {
                    insertId = i;
                    infinite = now[i].second;
                }
            }
            now[insertId] = std::make_pair(pages[id], time);
        }
        for (int i = 0; i < blockNum; i++) {
            tmp[i] = now[i].first;
        }
        result.push_back(tmp);
    }
    return result;
}

blocks_log op(const int blockNum, const pages_t &pages) {
    std::unordered_map<int, int> book; //pageNum -> nextId
    vector<int> next(pages.size(), INF);
    for (int i = int(pages.size() - 1); ~i; i--) {
        if (book.count(pages[i])) {
            next[i] = book[pages[i]];
        }
        book[pages[i]] = i;
    }
    return op_and_lru(blockNum, pages, true, &next);
}

blocks_log lru(const int blockNum, const pages_t &pages) {
    return op_and_lru(blockNum, pages, false);
}

pair<double, double> missing_and_displacement(const blocks_log &log) {
    double missing = 0, displacement = 0;
    for (auto i = log.begin(); i != log.end(); i++)
        if (i == log.begin())
            missing += 1;
        else if (*i != i[-1]) {
            missing += 1;
            if (find(i[-1].begin(), i[-1].end(), NOPAGE) == i[-1].end())
                displacement += 1;
        }
    return make_pair(missing / log.size(), displacement / log.size());
}
