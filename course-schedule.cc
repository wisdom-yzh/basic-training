#include <vector>
#include <stack>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0) {
            return true;
        }
        const int SIZE = numCourses;
        bool graph[SIZE][SIZE];
        int degree[SIZE];
        memset(graph, 0, sizeof(graph));
        memset(degree, 0, sizeof(degree));

        for (auto p: prerequisites) {
            graph[p.first][p.second] = true;
            degree[p.second]++;
        }

        stack<int> vertexs;
        for (int i = 0; i < SIZE; i++) {
            if (degree[i] == 0) {
                vertexs.push(i);
            }
        }
        for (;;) {
            if (vertexs.empty()) {
                break;
            }
            int v = vertexs.top();
            vertexs.pop();
            for (int i = 0; i < SIZE; i++) {
                if (graph[v][i]) {
                    degree[i]--;
                    if (degree[i] == 0) {
                        vertexs.push(i);
                    }
                }
            }
        }

        for (int i = 0; i < SIZE; i++) {
            if (degree[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<pair<int, int>> v {
        make_pair(1, 0)
    };
    cout << boolalpha << Solution().canFinish(2, v);
    return 0;
}
