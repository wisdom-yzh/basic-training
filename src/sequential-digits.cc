#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    static constexpr int NUMS[] = {
        12, 23, 34, 45, 56, 67, 78, 89,
        123, 234, 345, 456, 567, 678, 789,
        1234, 2345, 3456,4567, 5678, 6789,
        12345, 23456, 34567, 45678, 56789,
        123456, 234567, 345678, 456789,
        1234567, 2345678, 3456789,
        12345678, 23456789,
        123456789
    };

    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for (int i = 0; i < 36; i++) {
            int num = NUMS[i];
            if (num >= low && num <= high) {
                res.push_back(num);
            }
        }
        return res;
    }
};

constexpr int Solution::NUMS[];

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int low = stringToInteger(line);
        getline(cin, line);
        int high = stringToInteger(line);

        vector<int> ret = Solution().sequentialDigits(low, high);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
