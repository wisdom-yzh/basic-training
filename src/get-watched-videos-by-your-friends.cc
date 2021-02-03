#include <vector>
#include <iostream>
#include <tuple>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        map<string, int> count;
        vector<bool> used(friends.size(), false);

        queue<pair<int, int>> q;
        used[id] = true;
        q.push({ id, 0 });

        while (!q.empty()) {
            auto &top = q.front();
            used[top.first] = true;

            if (top.second == level) {
                for (auto &s: watchedVideos[top.first]) {
                    count[s]++;
                }
            } else {
                for (auto &nextId: friends[top.first]) {
                    if (!used[nextId]) {
                        used[nextId] = true;
                        q.push({ nextId, top.second + 1 });
                    }
                }
            }

            q.pop();
        }

        vector<string> res;
        for (auto &p: count) {
            res.push_back(p.first);
        }
        std::sort(res.begin(), res.end(), [&](string &a, string &b) {
            if (count[a] == count[b]) {
                return a < b;
            }
            return count[a] < count[b];
        });
        return res;
    }
};

int main() {
    vector<tuple<vector<vector<string>>, vector<vector<int>>, int, int>> testCases {
        { {{"A","B"},{"C"},{"B","C"},{"D"}}, {{1,2},{0,3},{0,3},{1,2}}, 0, 1 },
        { {{"A","B"},{"C"},{"B","C"},{"D"}}, {{1,2},{0,3},{0,3},{1,2}}, 0, 2 },
    };
    for (auto &tc: testCases) {
        for (auto &x: Solution().watchedVideosByFriends(get<0>(tc), get<1>(tc), get<2>(tc), get<3>(tc))) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
