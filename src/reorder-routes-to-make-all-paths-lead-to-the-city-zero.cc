#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        set<int> des;
        des.insert(0);

        int res = 0;

        while (des.size() != n) {
            for (auto &c : connections) {
                if (des.find(c[1]) != des.end()) {
                    des.insert(c[0]);
                } else if (des.find(c[0]) != des.end()) {
                    res++;
                    des.insert(c[1]);
                }
            }
        }
        return res;
    }
};

int main() {
    vector<pair<int, vector<vector<int>>>> testCases {
        { 6, {{0,1},{1,3},{2,3},{4,0},{4,5}} },
        { 5, {{1,0},{1,2},{3,2},{3,4}} },
        { 3, {{1,0},{2,0}} },
    };

    for (auto &testCase: testCases) {
        cout << Solution().minReorder(testCase.first, testCase.second) << endl;
    }

    return 0;
}
