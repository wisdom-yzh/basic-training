#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> result;

        int j = 0;
        for (int i = 1; i < S.size(); i++) {
            if (S[i] != S[i - 1]) {
                if (i - j >= 3) {
                    result.push_back(vector<int>({ j, i - 1 }));
                }
                j = i;
            }
        }

        if (S.size() - j >= 3) {
            result.push_back(vector<int>({ j, static_cast<int>(S.size()) - 1 }));
        }

        return result;
    }
};

int main() {
    Solution().largeGroupPositions("abcdddeeeeaabbbcd");
    return 0;
}
