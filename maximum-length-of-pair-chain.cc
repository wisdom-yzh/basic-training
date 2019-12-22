#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        std::sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });

        vector<int> longestChain(pairs.size(), 1);
        for (int i = 0; i < pairs.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    longestChain[i] = std::max(longestChain[i], longestChain[j] + 1);
                }
            }
        }

        return longestChain[pairs.size() - 1];
    }
};

int main() {
    vector<vector<int>> pairs({
        { 1, 2 },
        { 2, 3 },
        { 3, 4 }
    });
    std::cout << Solution().findLongestChain(pairs);
    return 0;
}
