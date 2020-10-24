#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        int height = log2(label);

        while (label > 1) {
            res.push_back(label);
            label >>= 1;
            label = (1 << (height - 1)) + (1 << height) - label - 1;
            height--;
        }

        res.push_back(1);
        reverse(res.begin(),res.end());
        return res;
    }
};

int main() {
    vector<int> testCases { 14, 26 };
    for (auto &label: testCases) {
        for (auto &num: Solution().pathInZigZagTree(label)) {
            cout << num << ' ';
        }
        cout << endl;
    }
    return 0;
}
