#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        std::map<int, int> dict;
        for (auto &x: arr) {
            dict[x]++;
        }

        vector<pair<int, int>> nums;
        for (auto &item: dict) {
            nums.push_back({ item.first, item.second });
        }

        std::sort(nums.begin(), nums.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second;
        });

        int p = 0;
        while (k > 0 && p < nums.size()) {
            if (k >= nums[p].second) {
                k -= nums[p].second;
                p++;
            } else {
                break;
            }
        }

        return nums.size() - p;
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
        vector<int> arr = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);

        int ret = Solution().findLeastNumOfUniqueInts(arr, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
