#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int result = 0;

        for (int i = 0; i < nums.size(); ) {
            int sum = 0;
            std::set<int> s{0};

            int j = i;
            for (; j < nums.size(); j++) {
                sum += nums[j];
                if (s.find(sum - target) != s.end()) {
                    result++;
                    j++;
                    break;
                } else {
                    s.insert(sum);
                }
            }
            i = j;
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
        int target = stringToInteger(line);

        int ret = Solution().maxNonOverlapping(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
