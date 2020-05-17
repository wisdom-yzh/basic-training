#include <vector>
#include <iostream>
#include <tuple>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> graph(n, vector<int>(n, -1));
        vector<vector<int>> cheapest(n, vector<int>(K + 1, 0));

        for (int i = 0; i < flights.size(); i++) {
            graph[flights[i][0]][flights[i][1]] = flights[i][2];
        }

        return this->recursionFindCheapestPrice(graph, cheapest, src, dst, K);
    }

    int recursionFindCheapestPrice(vector<vector<int>> &graph, vector<vector<int>> &cheapest,
            int src, int dst, int K) {
        if (src == dst) {
            return 0;
        }

        if (K == 0) {
            return graph[src][dst];
        }

        if (cheapest[src][K] != 0) {
            return cheapest[src][K];
        }

        cheapest[src][K] = -1;

        for (int i = 0; i < graph[src].size(); i++) {
            if (graph[src][i] == -1) {
                continue;
            }

            int nextPrice = this->recursionFindCheapestPrice(graph, cheapest, i, dst, K - 1);
            if (nextPrice != -1) {
                nextPrice += graph[src][i];
                if (cheapest[src][K] == -1 || cheapest[src][K] > nextPrice) {
                    cheapest[src][K] = nextPrice;
                }
            }
        }

        return cheapest[src][K];
    }
};


int main() {
    vector<vector<int>> flights {{1,0,5}};// {{0,1,100},{1,2,100},{0,2,500}};
    // cout << Solution().findCheapestPrice(3, flights, 0, 2, 0) << endl;
    cout << Solution().findCheapestPrice(2, flights, 0, 1, 1) << endl;
    return 0;
}
