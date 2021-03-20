#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> dict;

        for (auto &r: reservedSeats) {
            dict[r[0]] |= (1 << (r[1] - 1));
        }

        int res = (n - dict.size()) * 2;

        int a = 0b0111111110;
        int b = 0b0001111000;
        int c = 0b0111100000;
        int d = 0b0000011110;

        for (auto &item: dict) {
            int v = item.second;
            if ((v & a) == 0) {
                res += 2;
            } else if ((v & b) == 0 || (v & c) == 0 || (v & d) == 0) {
                res++;
            }
        }

        return res;
    }
};

int main() {
    vector<pair<int, vector<vector<int>>>> testCases {
        { 3, {{1,2},{1,3},{1,8},{2,6},{3,1},{3,10}} },
        { 2, {{2,1},{1,8},{2,6}} },
        { 4, {{4,3},{1,4},{4,6},{1,7}} }
    };
    for (auto &testCase: testCases) {
        cout << Solution().maxNumberOfFamilies(testCase.first, testCase.second) << endl;
    }
    return 0;
}
