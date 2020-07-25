#include <vector>
#include <stack>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        std::stack<int> stk;

        for (int i = 0; i < A.size(); i++) {
            if (stk.empty() || A[stk.top()] > A[i]) {
                stk.push(i);
            }
        }

        int result = 0;
        for (int i = A.size() - 1; i >= result; i--) {
            while (!stk.empty() && A[i] >= A[stk.top()]) {
                result = std::max(i - stk.top(), result);
                stk.pop();
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
        vector<int> A = stringToIntegerVector(line);

        int ret = Solution().maxWidthRamp(A);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
