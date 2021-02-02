#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> sum(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++) {
            sum[i] ^= sum[i - 1];
        }
        vector<int> res;
        for (auto &q: queries) {
            int left = q[0], right = q[1];
            if (left == 0) {
                res.push_back(sum[right]);
            } else {
                res.push_back(sum[right] ^ sum[left - 1]);
            }
        }
        return res;
    }
};

int main() {
    vector<pair<vector<int>, vector<vector<int>>>> testCases {
        { {1,3,4,8}, {{0,1},{1,2},{0,3},{3,3}} },
        { {4,8,2,10}, {{2,3},{1,3},{0,0},{0,3}} }
    };
    for (auto &testCase: testCases) {
        for (auto &x: Solution().xorQueries(testCase.first, testCase.second)) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
