#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;

        for (auto &log: logs) {
            if (log == "../") {
                depth = depth == 0 ? depth : depth - 1;
            } else if (log == "./") {
                // ...
            } else {
                depth++;
            }
        }

        return depth;
    }
};

int main() {
    vector<vector<string>> testCases {
        {"d1/","d2/","../","d21/","./"},
        {"d1/","d2/","./","d3/","../","d31/"},
        {"d1/","../","../","../"}
    };

    for (auto &testCase: testCases) {
        cout << Solution().minOperations(testCase) << endl;
    }

    return 0;
}
