#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

// range[i, j] = total - range[0, i-1] - range[j+1, size-1]
class NumArray {
public:
    NumArray(vector<int> nums) {
        total = accumulate(nums.begin(), nums.end(), 0);
        int subTotal = 0;
        for_each(nums.begin(), nums.end(), [&](int &n) {
            subTotal += n;
            fromHead.push_back(subTotal);
        });
        subTotal = 0;
        for_each(nums.rbegin(), nums.rend(), [&](int &n) {
            subTotal += n;
            fromTail.push_back(subTotal);
        });
    }

    int sumRange(int i, int j) {
        int size = fromHead.size();
        return total - (i > 0 ? fromHead[i - 1] : 0) - ((j < size - 1) ? fromTail[size - 2 - j] : 0);
   }

private:
    vector<int> fromHead, fromTail;
    int total;
};
