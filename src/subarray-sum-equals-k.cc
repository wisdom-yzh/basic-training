#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        vector<int> lSum, rSum;

        int sumOfArr = std::accumulate(nums.begin(), nums.end(), 0);
        int sumFromRight = sumOfArr;
        int sumFromLeft = 0;

        for (auto &num: nums) {
            sumFromLeft += num;
            lSum.push_back(sumFromLeft);
            rSum.push_back(sumFromRight);
            sumFromRight -= num;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                int sumOfRange = sumOfArr;
                if (i > 0) {
                    sumOfRange -= lSum[i - 1];
                }
                if (j < nums.size() - 1) {
                    sumOfRange -= rSum[j + 1];
                }
                if (sumOfRange == k) {
                    result++;
                }
            }
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

        int ret = Solution().subarraySum(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
