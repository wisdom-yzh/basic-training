#include <ios>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int p = 0;
        for (auto &g: groups) {
            if (!match(g, nums, p)) {
                return false;
            }
        }
        return true;
    }

    bool match(vector<int> &g, vector<int> &nums, int &p) {
        int i = p;
        while (i < nums.size()) {
            bool matched = true;
            for (int j = 0; j < g.size(); j++) {
                if (g[j] != nums[i + j]) {
                    matched = false;
                    break;
                }
            }
            if (matched) {
                p += i - p + g.size();
                return true;
            }
            i++;
        }
        return false;
    }
};

int main() {
    vector<pair<vector<vector<int>>, vector<int>>> testCases {
        { {{1,-1,-1},{3,-2,0} }, {1,-1,0,1,-1,-1,3,-2,0} },
        { {{10,-2},{1,2,3,4}}, {1,2,3,4,10,-2} },
        { {{1,2,3},{3,4}}, {7,7,1,2,3,4,7,7} },
    };
    for (auto &[groups, nums]: testCases) {
        cout << boolalpha << Solution().canChoose(groups, nums) << endl;
    }
    return 0;
}
