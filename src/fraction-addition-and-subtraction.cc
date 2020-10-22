#include <string>
#include <stack>
#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    enum Status {
        NUMERATOR,
        DENOMINATOR,
        OPERATOR
    };

    string fractionAddition(string expression) {
        Status status = Status::NUMERATOR;
        stack<pair<int, int>> nums;
        char op;
        bool lessThanZero = false;
        int numerator, denominator;

        int p = 0;
        while (p != expression.size()) {
            char ch = expression[p];
            p++;

            if (status == Status::OPERATOR) {
                op = ch;
                status = Status::NUMERATOR;
                continue;
            }

            if (ch == '-') {
                lessThanZero = true;
                continue;
            }

            // ch >= '0' && ch <= '9
            int number = static_cast<int>(ch - '0');
            int q = p;
            while (q < expression.size() && expression[q] >= '0' && expression[q] <= '9') {
                number = 10 * number + static_cast<int>(expression[q] - '0');
                q++;
            }
            if (status == NUMERATOR) {
                numerator = lessThanZero ? -number : number;
                status = Status::DENOMINATOR;
                p = q + 1;
            } else {
                denominator = lessThanZero ? -number : number;
                nums.emplace(make_pair(numerator, denominator));
                if (nums.size() == 2) {
                    calc(nums, op);
                }
                status = Status::OPERATOR;
                p = q;
            }
            lessThanZero = false;
        }
        return std::to_string(nums.top().first) + "/" + std::to_string(nums.top().second);
    }

    void calc(stack<pair<int, int>> &s, char op) {
        const pair<int, int> &b = s.top();
        s.pop();
        const pair<int, int> &a = s.top();
        s.pop();

        int numerator, denominator;
        denominator = a.second * b.second;
        if (op == '+') {
            numerator = a.first * b.second + a.second * b.first;
        } else {
            numerator = a.first * b.second - a.second * b.first;
        }

        if (numerator == 0) {
            s.push(make_pair(0, 1));
        } else {
            int g = gcd(numerator, denominator);
            s.push(make_pair(numerator / g, denominator / g));
        }
    }

    int gcd(int a, int b) {
        if (a < 0) a = -a;
        if (a < b) std::swap(a, b);
        return a % b == 0 ? b : gcd(b, a % b);
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string expression = stringToString(line);

        string ret = Solution().fractionAddition(expression);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
