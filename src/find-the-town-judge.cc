#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> inDegree(N + 1, 0), outDegree(N + 1, 0);
        for (const auto &p: trust) {
            inDegree[p[1]]++;
            outDegree[p[0]]++;
        }
        for (int i = 1; i <= N; i++) {
            if (inDegree[i] == N - 1 && outDegree[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    vector<pair<int, vector<vector<int>>>> testCases {
        { 2, {{1,2}} },
        { 3, {{1,2},{2,3}} },
        { 3, {{1,3},{2,3},{3,1}} },
        { 4, {{1,3},{1,4},{2,3},{2,4},{4,3}} }
    };

    for (auto &testCase: testCases) {
        cout << Solution().findJudge(testCase.first, testCase.second) << endl;
    }
    return 0;
}
