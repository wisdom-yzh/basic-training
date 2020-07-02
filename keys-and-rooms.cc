#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size(), total = 0;
        vector<bool> visited(size, false);
        queue<int> q;

        visited[0] = true;
        q.push(0);

        while (!q.empty()) {
            total++;
            auto &topIndex = q.front();
            auto &nextRooms = rooms[topIndex];
            for (const auto &r: nextRooms) {
                if (!visited[r]) {
                    q.push(r);
                    visited[r] = true;
                }
            }
            q.pop();
        }

        return total == size;
    }
};

int main() {
    vector<vector<vector<int>>> cases {
        { {1}, {2}, {3}, {} },
        { {1,3}, {3,0,1}, {2}, {0} }
    };
    for (auto &c: cases) {
        cout << Solution().canVisitAllRooms(c) << endl;
    }
    return 0;
}
