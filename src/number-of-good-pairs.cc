#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        std::map<int, int> d;

        for (auto &num: nums) {
            d[num]++;
        }

        for (auto &p: d) {
            if (p.second >= 2) {
                res += combine(p.second, 2);
            }
        }

        return res;
    }

    int combine(int n, int k) {
        int N = 1, K = 1;

        for (int i = 0; i < k; i++) {
            N *= n - i;
            K *= k - i;
        }

        return N / K;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().numIdenticalPairs(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
