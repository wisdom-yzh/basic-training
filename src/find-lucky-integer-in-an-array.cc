#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> cnt(501, 0);
        for (auto &x: arr) {
            cnt[x]++;
        }
        int result = -1;
        for (int i = 1; i < cnt.size(); i++) {
            if (cnt[i] == i) {
                result = i;
            }
        }
        return result;
    }
};



int main() {
    vector<vector<int>> testCases {
        { 2,2,3,4 },
        { 1,2,2,3,3,3 },
        { 2,2,2,3,3 }
    };
    return 0;
}
