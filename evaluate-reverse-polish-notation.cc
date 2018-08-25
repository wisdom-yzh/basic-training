#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) {
            return 0;
        }
        stack<int> nums;
        for (auto &token: tokens) {
            if (token == "+") {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(b + a);
            } else if (token == "-") {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(b - a);
            } else if (token == "*") {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(b * a);
            } else if (token == "/") {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(static_cast<int>(b / a));
            } else {
                nums.push(std::stoi(token));
            }
        }
        return nums.top();
    }
};

int main() {
    vector<string> tokens {
        "4", "13", "5", "/", "+"
    };
    cout << Solution().evalRPN(tokens) << endl;
    return 0;
}
