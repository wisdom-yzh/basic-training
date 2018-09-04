#include <vector>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); i++) {
            auto p = m.find(nums[i]);
            if (p == m.end()) {
                vector<int> vec { i };
                m.insert(make_pair(nums[i], vec));
            } else {
                for (auto &n: p->second) {
                    if (abs(n - i) <= k) {
                        return true;
                    }
                }
                p->second.push_back(i);
            }
        }
        return false;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);

        bool ret = Solution().containsNearbyDuplicate(nums, k);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
