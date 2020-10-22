#include <vector>
#include <iostream>
#include <sstream>
#include <array>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        std::array<int, 50000> left, right, degree;
        int maxDegree = 0, result = nums.size();

        left.fill(-1);
        right.fill(-1);
        degree.fill(0);

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            degree[num]++;

            if (left[num] == -1) {
                left[num] = i;
            }
            right[num] = i;

            if (degree[num] >= maxDegree) {
                if (degree[num] > maxDegree) {
                    result = right[num] - left[num] + 1;
                } else {
                    result = std::min(result, right[num] - left[num] + 1);
                }
                maxDegree = degree[num];
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().findShortestSubArray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
