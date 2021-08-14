#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> incoming(n, 0);
        for (auto &e: edges) {
            incoming[e[1]]++;
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (incoming[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main() {
    vector<pair<int, vector<vector<int>>>> testCases {
        { 6, {{0,1},{0,2},{2,5},{3,4},{4,2}} },
        { 5, {{0,1},{2,1},{3,1},{1,4},{2,4}} },
    };

    for (auto &testCase: testCases) {
        for (auto &x: Solution().findSmallestSetOfVertices(testCase.first, testCase.second)) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
