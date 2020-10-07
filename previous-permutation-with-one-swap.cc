#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size();
        for (int i = n - 2; i >= 0; i--) {
            int maxDigit = -1;
            int maxVal = -1;
            for (int j = i + 1; j < n; j++) {
                if (A[j] < A[i] && A[j] > maxVal) {
                    maxDigit = j;
                    maxVal = A[j];
                }
            }
            if (maxDigit != -1) {
                swap(A[i], A[maxDigit]);
                return A;
            }
        }
        return A;
    }
};

int main() {
    vector<vector<int>> testCases {
        {3,2,1},
        {1,1,5},
        {1,9,4,6,7},
        {3,1,1,3}
    };
    for (auto &testCase: testCases) {
        for (const auto &el: Solution().prevPermOpt1(testCase)) {
            cout << el << ' ';
        }
        cout << endl;
    }
    return 0;
}
