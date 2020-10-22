#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    // 用牛顿迭代法计算x^2 - num = 0是否存在正整数解
    bool isPerfectSquare(int num) {
        double x0 = num, x, eps = 1e-3;
        while (true) {
            x = (num + x0 * x0) / (2 * x0);
            if (abs(x - x0) < eps) {
                break;
            }
            x0 = x;
        }
        return abs(x - static_cast<int>(x)) < eps ||
            abs(x - static_cast<int>(x + 1)) < eps;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        bool ret = Solution().isPerfectSquare(num);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
