#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for (int i = 0; i < l.size(); i++) {
            res.push_back(check(nums, l[i], r[i]));
        }
        return res;
    }

    bool check(vector<int>& nums, int l, int r) {
        vector<int> seq;
        for (int i = l; i <= r; i++) {
            seq.push_back(nums[i]);
        }
        std::sort(seq.begin(), seq.end());

        for (int i = 1; i < seq.size() - 1; i++) {
            if (seq[i + 1] - seq[i] != seq[i] - seq[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<tuple<vector<int>, vector<int>, vector<int>>> testCases {
        { { 4,6,5,9,3,7 }, { 0,0,2 }, { 2,3,5 } },
        { { -12,-9,-3,-12,-6,15,20,-25,-20,-15,-10 }, { 0,1,6,4,8,7 }, { 4,4,9,7,9,10 } },
    };
    for (auto &[nums, l, r]: testCases) {
        for (const auto &x: Solution().checkArithmeticSubarrays(nums, l, r)) {
            cout << boolalpha << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
