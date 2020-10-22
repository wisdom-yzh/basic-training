#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (!M.size()) {
            return 0;
        }
        int circle = 0;
        for (int r = 0; r < M.size(); r++) {
            circle += bfs(M, r);
        }
        return circle;
    }

    int bfs(vector<vector<int>> &M, int index) {
        bool hasFriends = false;
        queue<int> q;
        q.push(index);

        while (!q.empty()) {
            int r = q.front();
            q.pop();

            for (int c = 0; c < M.size(); c++) {
                if (M[r][c] == 1) {
                    hasFriends = true;
                    M[r][c] = M[c][r] = 0;
                    if (r != c) {
                        q.push(c);
                    }
                }
            }
        }

        return hasFriends ? 1 : 0;
    }
};

int main() {
    vector<vector<vector<int>>> cases {
        {
            {1,1,0},
            {1,1,0},
            {0,0,1}
        },
        {
            {1,1,0},
            {1,1,1},
            {0,1,1}
        }
    };

    for (auto & m: cases) {
        std::cout << Solution().findCircleNum(m) << std::endl;
    }
    return 0;
}
