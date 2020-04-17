#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; i++) {
            if (isSelfDividingNumber(i))  {
                result.push_back(i);
            }
        }
        return result;
    }

    bool isSelfDividingNumber(int num) {
        int r = num;
        while (r != 0) {
            int mod = r % 10;
            if ((mod != 0) && (num % mod == 0)) {
                r /= 10;
                continue;
            }
            return false;
        }
        return true;
    }
};

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
        int left = stringToInteger(line);
        getline(cin, line);
        int right = stringToInteger(line);

        vector<int> ret = Solution().selfDividingNumbers(left, right);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
