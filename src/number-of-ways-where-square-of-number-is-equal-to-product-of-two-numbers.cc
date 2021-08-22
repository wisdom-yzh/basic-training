#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include <iterator>
using namespace std;

class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        map<uint64_t, uint64_t> m1, m2;
        for (auto &n: nums1) {
            m1[1l * n * n]++;
        }
        for (auto &n: nums2) {
            m2[1l * n * n]++;
        }

        return count(m1, nums2) + count(m2, nums1);
    }

    int count(map<uint64_t, uint64_t> &m, vector<int> &s) {
        int res = 0;
        for (auto &[m, mCount]: m) {
            for (int i = 0; i < s.size() - 1; i++) {
                for (int j = i + 1; j < s.size(); j++) {
                    if (1l * s[i] * s[j] == m) {
                        res += mCount;
                    }
                }
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);

        int ret = Solution().numTriplets(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
