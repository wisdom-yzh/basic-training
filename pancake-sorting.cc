#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> result;
        int size = A.size();
        while (size > 1) {
            int maxIndex = this->findMaxIndex(A, size);
            if (maxIndex != size - 1) {
                if (maxIndex != 0) {
                    result.push_back(maxIndex + 1);
                }
                result.push_back(size);
            }
            std::reverse(A.begin(), std::next(A.begin(), maxIndex + 1));
            std::reverse(A.begin(), std::next(A.begin(), size));
            size--;
        }
        return result;
    }

    int findMaxIndex(vector<int> &A, int size) {
        int maxValue = std::numeric_limits<int>::min(), index = -1;
        for (int i = 0; i < size; i++) {
            if (A[i] > maxValue) {
                maxValue = A[i];
                index = i;
            }
        }
        return index;
    }
};

int main() {
    vector<vector<int>> cases {
        {3,2,4,1},
        // {1,2,3}
    };
    for (auto &cs: cases) {
        for (const auto &num: Solution().pancakeSort(cs)) {
            cout << num << ' ';
        }
        cout << endl;
    }
    return 0;
}
