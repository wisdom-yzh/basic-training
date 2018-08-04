#include <vector>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;


class Solution {
public:
    // f(0) = [0]
    // f(1) = [0, 1]
    // f(2) = [0, 1, 3, 2]
    // f(3) = [0, 1, 3, 2, 6, 7, 5, 4]
    // f(n) = concat(f(n-1), reverse(f(n-1)+2^(n-1)))
    vector<int> grayCode(int n) {
        if (n == 0) {
            return vector<int>{0};
        } else if (n == 1) {
            return vector<int>{0, 1};
        } else {
            vector<int> result = this->grayCode(n - 1);
            int addOffset = 1 << (n - 1);
            for (int i = result.size() - 1; i >= 0; i--) {
                result.push_back(result[i] + addOffset);
            }
            return result;
        }
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
        int n = stringToInteger(line);
        
        vector<int> ret = Solution().grayCode(n);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
