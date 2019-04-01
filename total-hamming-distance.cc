#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0, size = nums.size();
        for (int i = 0; i < 32; i++) {
            int bitCount = 0;
            for (int j = 0; j < size; j++) {
                if (((nums[j] >> i) & 1) == 1) {
                    bitCount++;
                }
            }
            total += bitCount * (size - bitCount);
        }
        return total;
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

        int ret = Solution().totalHammingDistance(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
