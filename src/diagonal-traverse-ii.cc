#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<tuple<int, int, int>> arr;
        for (int y = 0; y < nums.size(); y++) {
            for (int x = 0; x < nums[y].size(); x++) {
                arr.push_back({ x + y, y, nums[y][x] });
            }
        }

        std::sort(arr.begin(), arr.end(), [](tuple<int, int, int> &a, tuple<int, int, int> &b) {
            if (get<0>(a) == get<0>(b)) {
                return get<1>(a) > get<1>(b);
            }
            return get<0>(a) < get<0>(b);
        });

        vector<int> res;
        std::transform(arr.begin(), arr.end(), std::back_inserter(res), [](tuple<int, int, int> &x) {
            return get<2>(x);
        });
        return res;
    }
};

int main() {
    vector<vector<vector<int>>> testCases {
        {
            {1,2,3},
            {4,5,6},
            {7,8,9}
        },
        {
            {1,2,3,4,5},
            {6,7},
            {8},
            {9,10,11},
            {12,13,14,15,16}
        },
        {
            {1,2,3},
            {4},
            {5,6,7},
            {8},
            {9,10,11}
        },
        {
            {1,2,3,4,5,6}
        }
    };
    for (auto &testCase: testCases) {
        for (auto &x: Solution().findDiagonalOrder(testCase)) {
            cout << x << ',';
        }
        cout << endl;
    }
    return 0;
}
