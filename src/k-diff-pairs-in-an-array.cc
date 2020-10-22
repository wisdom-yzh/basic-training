#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.empty() || nums.size() < 2) {
            return 0;
        }
        std::set<std::pair<int, int>> pairNum;
        std::sort(nums.begin(), nums.end());

        int i = 0, j = 1;
        int result = 0;
        while (j < nums.size()) {
            if (std::abs(nums[j] - nums[i]) < k) {
                j++;
                continue;
            }
            if (std::abs(nums[j] - nums[i]) > k) {
                i++;
                if (i == j) {
                    j++;
                }
                continue;
            }

            auto pair = std::make_pair(nums[i], nums[j]);
            if (pairNum.find(pair) == pairNum.end()) {
                result++;
                pairNum.emplace(pair);
            }
            i++;
            j++;
        }

        return result;
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
        int k = stringToInteger(line);

        int ret = Solution().findPairs(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
