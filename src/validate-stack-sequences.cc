#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i = 0, j = 0;

        while (i < pushed.size()) {
            while (!stk.empty() && stk.top() == popped[j]) {
                stk.pop();
                j++;
            }

            if (pushed[i] == popped[j]) {
                i++;
                j++;
            } else {
                stk.push(pushed[i]);
                i++;
            }
        }

        while (!stk.empty()) {
            if (stk.top() != popped[j]) {
                break;
            }
            stk.pop();
            j++;
        }
        return j == popped.size();
    }
};

int main() {
    vector<pair<vector<int>, vector<int>>> testCases {
        {{1,2,3,4,5}, {4,5,3,2,1}},
        {{1,2,3,4,5}, {4,3,5,1,2}}
    };
    for (auto &testCase: testCases) {
        cout << boolalpha << Solution().validateStackSequences(testCase.first, testCase.second) << endl;
    }
    return 0;
}
