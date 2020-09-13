#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int max = 0, i = 0;
        for (int j = 1; j < A.size(); j++) {
            int s1 = A[i] + A[j] + i - j;
            int s2 = A[j - 1] + A[j] - 1;
            if (s1 < s2) {
                i = j - 1;
            }
            max = std::max(max, std::max(s1, s2));
        }
        return max;
    }
};

int main() {
    vector<vector<int>> testCases { {8,1,5,2,6} };
    for (auto &testCase: testCases) {
        cout << Solution().maxScoreSightseeingPair(testCase) << endl;
    }
    return 0;
}
