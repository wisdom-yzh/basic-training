#include <numeric>
#include <pthread.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = std::accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = std::accumulate(nums2.begin(), nums2.end(), 0);
        if (sum1 < sum2) {
            return minOp(nums1, nums2, sum2 - sum1);
        } else if (sum1 > sum2) {
            return minOp(nums2, nums1, sum1 - sum2);
        } else {
            return 0;
        }
    }

    int minOp(vector<int> &small, vector<int> &big, int diff) {
        int add[6] { 0 };
        int sub[6] { 0 };

        for (auto &num: small) {
            add[6 - num]++;
        }
        for (auto &num: big) {
            sub[num - 1]++;
        }

        int op = 0;
        for (int i = 5; i >= 1; i--) {
            while (add[i] > 0) {
                add[i]--;
                diff -= i;
                op++;
                if (diff <= 0) {
                    return op;
                }
            }
            while (sub[i] > 0) {
                sub[i]--;
                diff -= i;
                op++;
                if (diff <= 0) {
                    return op;
                }
            }
        }
        return (diff > 0) ? -1 : op;
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
        
        int ret = Solution().minOperations(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
