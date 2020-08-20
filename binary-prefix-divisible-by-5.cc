#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int num = 0;
        vector<bool> result(A.size(), false);
        for (int i = 0; i < A.size(); i++) {
            num += A[i];
            result[i] = num % 5 == 0;
            num = (num << 1) % 5;
        }
        return result;
    }
};

int main() {
    vector<vector<int>> testCases {
        //{ 0, 1, 1 },
        //{ 1, 1, 1 },
        { 0,1,1,1,1,1 },
        //{ 1,1,1,0,1 }
    };
    for (auto &testCase: testCases) {
        for (auto b: Solution().prefixesDivBy5(testCase)) {
            cout << boolalpha << b << ' ';
        }
        cout << endl;
    }
    return 0;
}
