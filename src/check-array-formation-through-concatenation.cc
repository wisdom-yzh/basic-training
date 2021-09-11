#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        vector<bool> used(arr.size(), false);
        for (auto &piece: pieces) {
            int &x = piece[0];

            auto p = std::find(arr.begin(), arr.end(), x);
            if (p == arr.end() || distance(p, arr.end()) < piece.size()) {
                return false;
            }

            auto idx = distance(arr.begin(), p);
            if (used[idx]) {
                return false;
            }
            used[idx] = true;

            for (int i = 1; i < piece.size(); i++) {
                if (arr[idx + i] != piece[i] || used[idx + i]) {
                    return false;
                }
                used[idx + i] = true;
            }
        }
        return std::find(used.begin(), used.end(), false) == used.end();
    }
};

int main() {
    vector<pair<vector<int>, vector<vector<int>>>> testCases {
        {{85}, {{85}}},
        {{15,88}, {{88},{15}}},
        {{49,18,16}, {{16,18,49}}},
        {{91,4,64,78}, {{78},{4,64},{91}}},
        {{1,3,5,7}, {{2,4,6,8}}}
    };
    for (auto &[arr, pieces]: testCases) {
        cout << boolalpha << Solution().canFormArray(arr, pieces) << endl;
    }
    return 0;
}
