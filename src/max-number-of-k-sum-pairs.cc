#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (auto &num: nums) {
            count[num]++;
        }

        int res = 0;
        for (auto iter = count.begin(); iter != count.end(); ) {
            if (iter->first == k - iter->first) {
                res += (iter->second >> 1);
            } else if (k > iter->first) {
                auto iter2 = count.find(k - iter->first);
                if (iter2 != count.end()) {
                    res += std::min(iter->second, iter2->second);
                    count.erase(iter2);
                }
            }
            iter = count.erase(iter);
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
        int k = stringToInteger(line);

        int ret = Solution().maxOperations(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
