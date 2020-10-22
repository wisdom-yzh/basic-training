#include <vector>
#include <string>
#include <cstdlib>
#include <map>
#include <set>
#include <tuple>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    static int DIRECTION[8][4];

    int openLock(vector<string>& deadends, string target) {
        std::queue<std::pair<string, int>> q;
        std::set<string> visited;
        std::map<string, int> paths;

        for (const auto &deadend: deadends) {
            if (deadend == "0000") {
                return -1;
            }
            visited.emplace(std::move(deadend));
        }

        bool targetFound = false;
        q.push(make_pair("0000", 0));
        while (!q.empty() && !targetFound) {
            string coord;
            int dist;

            std::tie(coord, dist) = std::move(q.front());
            paths[coord] = dist;

            for (int i = 0; i < 8; i++) {
                string neighbour(coord);
                for (int j = 0; j < 4; j++) {
                    neighbour[j] = ((neighbour[j] - '0' + DIRECTION[i][j] + 10) % 10) + '0';
                }
                if (neighbour == target) {
                    return dist + 1;
                }
                if (visited.emplace(neighbour).second) {
                    q.push(make_pair(std::move(neighbour), dist + 1));
                }
            }

            q.pop();
        }

        auto iter = paths.find(target);
        return iter == paths.end() ? -1 : iter->second;
    }
};

int Solution::DIRECTION[8][4] = {
    { 1, 0, 0, 0 },
    { 0, 1, 0, 0 },
    { 0, 0, 1, 0 },
    { 0, 0, 0, 1 },
    { -1, 0, 0, 0 },
    { 0, -1, 0, 0 },
    { 0, 0, -1, 0 },
    { 0, 0, 0, -1 },
};

int main() {
    // vector<string> deadends { "0201","0101","0102","1212","2002" };
    vector<string> deadends { "8888" };
    cout << Solution().openLock(deadends, "0009");
    return 0;
}
