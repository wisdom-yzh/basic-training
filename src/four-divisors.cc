#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;

        for (auto &num: nums) {
            int divNums = 0, divVal = 0;

            for (int i = 1; i * i <= num; i++) {
                if ((num % i) == 0) {
                    divNums++;
                    divVal += i;

                    int j = num / i;
                    if (i != j) {
                        divNums++;
                        divVal += j;
                    }

                }
            }

            if (divNums == 4) {
                res += divVal;
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
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().sumFourDivisors(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
