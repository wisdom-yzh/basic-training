#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    using XCOORD = int;
    using YCOORD = int;

    int removeStones(vector<vector<int>>& stones) {
        std::map<XCOORD, std::set<YCOORD>> collection;
        std::map<XCOORD, int> maxSizeDict;
        for (const auto &stone: stones) {
            collection[stone[0]].insert(stone[1]);
            maxSizeDict[stone[0]]++;
        }

        for (auto i = collection.begin(); i != collection.end();) {
            auto unionCollectionIter = collection.end();
            for (auto j = collection.begin(); j != collection.end() && unionCollectionIter == collection.end(); j = next(j)) {
                if (i == j) continue;
                for (auto &y: j->second) {
                    if (i->second.find(y) != i->second.end()) {
                        unionCollectionIter = j;
                        break;
                    }
                }
            }

            if (unionCollectionIter != collection.end()) {
                for (auto &y: unionCollectionIter->second) {
                    i->second.insert(y);
                }
                maxSizeDict[i->first] += maxSizeDict[unionCollectionIter->first];
                maxSizeDict.erase(maxSizeDict.find(unionCollectionIter->first));
                collection.erase(unionCollectionIter);
            } else {
                i = collection.erase(i);
            }
        }

        int result = 0;
        for (auto &size: maxSizeDict) {
            result += size.second - 1;
        }
        return result;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}},
        {{0,0},{0,2},{1,1},{2,0},{2,2}},
        {{0,0}},
        {{3,2},{3,1},{4,4},{1,1},{0,2},{4,0}},
        {{1,2},{3,2},{3,0},{4,4},{4,2},{2,4},{4,0}}
    };
    for (auto &testCase: testCases) {
        cout << Solution().removeStones(testCase) << endl;
    }
    return 0;
}
