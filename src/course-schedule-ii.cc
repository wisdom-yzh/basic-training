#include <vector>
#include <iostream>
#include <cstdlib>
#include <set>
#include <queue>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        const int SIZE = numCourses;
        bool graph[SIZE][SIZE];
        int degree[SIZE];
        memset(graph, 0, sizeof(graph));
        memset(degree, 0, sizeof(degree));

        for (auto &p: prerequisites) {
            graph[p.second][p.first] = true;
            degree[p.first]++;
        }

        queue<int> toplogy;
        vector<int> result;
        for (auto i = 0; i < SIZE; i++) {
            if (degree[i] == 0) {
                toplogy.push(i);
            }
        }

        while (!toplogy.empty()) {
            int v = toplogy.front();
            result.push_back(v);
            for (int i = 0; i < SIZE; i++) {
                if (graph[v][i]) {
                    degree[i]--;
                    if (degree[i] == 0) {
                        toplogy.push(i);
                    }
                }
            }
            toplogy.pop();
        }
        if (result.size() < SIZE) {
            return vector<int>();
        }
        return result;
    }
};

int main() {
    vector<pair<int, int>> p {
        make_pair(1, 0),
        make_pair(2, 0),
        make_pair(3, 1),
        make_pair(3, 2),
    };
    for (auto &x: Solution().findOrder(4, p)) {
        cout << x << ',';
    }
    cout << endl;
    vector<pair<int, int>> p2 {
        make_pair(1, 0),
    };
    for (auto &x: Solution().findOrder(2, p2)) {
        cout << x << ',';
    }
    cout << endl;
    vector<pair<int, int>> p3 {
        make_pair(0, 1),
    };
    for (auto &x: Solution().findOrder(2, p3)) {
        cout << x << ',';
    }
    cout << endl;
    vector<pair<int, int>> p4 {
        make_pair(0, 1),
        make_pair(0, 2),
        make_pair(1, 2),
    };
    for (auto &x: Solution().findOrder(3, p4)) {
        cout << x << ',';
    }
    cout << endl;
    vector<pair<int, int>> p5 {
        make_pair(1, 0),
        make_pair(1, 2),
        make_pair(0, 1),
    };
    for (auto &x: Solution().findOrder(3, p5)) {
        cout << x << ',';
    }
    cout << endl;
    return 0;
}
