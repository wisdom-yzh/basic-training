#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

class Solution {
public:
    vector<vector<int>> sum;

    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int maxValue = 0;
        sum.assign(A.size(), vector<int>(A.size(), -1));

        int sumL = 0, sumM = 0;
        for (int i = 0; i < L; i++) {
            sumL += A[i];
            sum[0][i] = sumL;
        }
        for (int i = L; i < A.size(); i++) {
            sumL = sumL - A[i - L] + A[i];
            sum[i - L + 1][i] = sumL;
        }
        for (int i = 0; i < M; i++) {
            sumM += A[i];
            sum[0][i] = sumM;
        }
        for (int i = M; i < A.size(); i++) {
            sumM = sumM - A[i - M] + A[i];
            sum[i - M + 1][i] = sumM;
        }

        for (int i = 0; i < A.size() - L + 1; i++) {
            maxValue = std::max(
                maxValue,
                sum[i][i + L - 1] + std::max(maxSumOfM(0, i - 1, M), maxSumOfM(i + L, A.size() - 1, M))
            );
        }

        return maxValue;
    }

    int maxSumOfM(int begin, int end, int M) {
        int maxValue = 0;
        while (begin + M - 1 <= end) {
            maxValue = std::max(maxValue, sum[begin][begin + M - 1]);
            begin++;
        }
        return maxValue;
    }
};

int main() {
    vector<tuple<vector<int>, int, int>> testCases {
        {{0,6,5,2,2,5,1,9,4}, 1, 2},
        {{3,8,1,3,2,1,8,9,0}, 3, 2},
        {{2,1,5,6,0,9,5,0,3,8}, 4, 3}
    };
    for (auto &testCase: testCases) {
        cout << Solution().maxSumTwoNoOverlap(get<0>(testCase), get<1>(testCase), get<2>(testCase)) << endl;
    }
    return 0;
}
