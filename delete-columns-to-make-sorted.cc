#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int res = 0;
        const int len = A[0].size();
        for (int j = 0; j < len; j++) {
            for (int i = 0; i < A.size() - 1; i++) {
                if (A[i + 1][j] < A[i][j]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<string> A { "cba", "daf", "ghi" };
    cout << Solution().minDeletionSize(A);
    vector<string> B { "zyx", "wvu", "tsr" };
    cout << Solution().minDeletionSize(B);
    return 0;
}
