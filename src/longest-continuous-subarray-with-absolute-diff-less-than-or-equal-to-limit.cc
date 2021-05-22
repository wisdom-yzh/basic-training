#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <iterator>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        std::multiset<int> s;
        int p = 0, q = 0, res = 0;

        s.insert(nums[0]);

        while (true) {
            int min = *s.begin();
            int max = *prev(s.end());
            if (max - min <= limit) {
                res = std::max(res, q - p + 1);
                if (q < nums.size() - 1) {
                    q++;
                    s.insert(nums[q]);
                } else {
                    break;
                }
            } else {
                s.erase(s.find(nums[p]));
                p++;
            }
        }

        return res;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                return !isspace(ch);
                }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int limit = stringToInteger(line);

        int ret = Solution().longestSubarray(nums, limit);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
