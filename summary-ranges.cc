#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) {
            return result;
        }
        vector<int> temp;
        int num, prevNum;
        for (auto iter = nums.begin(); iter != nums.end(); iter++) {
            prevNum = num;
            num = *iter;
            if (iter != nums.begin() && prevNum == num - 1) {
                temp.push_back(num);
            } else {
                if (iter != nums.begin()) {
                    if (temp.size() == 1) {
                        result.push_back(to_string(temp[0]));
                    } else {
                        result.push_back(
                            to_string(temp[0]) + "->" +
                            to_string(temp[temp.size() - 1])
                        );
                    }
                }
                temp.clear();
                temp.push_back(num);
            }
        }
        if (temp.size() == 1) {
            result.push_back(to_string(temp[0]));
        } else {
            result.push_back(
                to_string(temp[0]) + "->" +
                to_string(temp[temp.size() - 1])
            );
        }
        return result;
    }
};

int main() {
    vector<int> nums {0,2,3,4,6,8,9};
    for (auto &s: Solution().summaryRanges(nums)) {
        cout << s << endl;
    }
    return 0;
}
