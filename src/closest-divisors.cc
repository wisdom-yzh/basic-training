#include <vector>
#include <string>
#include <iostream>
#include <tuple>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> closestDivisors(int num) {
        int a, b, c, d;
        std::tie(a, b) = closest(num + 1);
        std::tie(c, d) = closest(num + 2);
        if (c - d > a - b) {
            return { a, b };
        }
        return { c, d };
    }

    pair<int, int> closest(int num) {
        int s = static_cast<int>(std::sqrt(num));

        for (int i = s; i >= 1; i--) {
            if (num % i == 0) {
                return { num / i, i };
            }
        }

        return { 1, num };
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
        int num = stringToInteger(line);

        vector<int> ret = Solution().closestDivisors(num);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
