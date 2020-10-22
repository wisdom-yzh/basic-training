#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        std::unordered_set<int> s;

        for (const auto &num: A) {
            if (!s.insert(num).second) {
                return num;
            }
        }
        return 0;
    }
};

int main() {
    vector<vector<int>> testCases {
        {1,2,3,3},
        {2,1,2,5,3,2},
        {5,1,5,2,5,3,5,4},
    };
    for (auto &testCase: testCases) {
        cout << Solution().repeatedNTimes(testCase) << endl;
    }
    return 0;
}
