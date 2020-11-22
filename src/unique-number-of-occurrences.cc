#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::unordered_map<int, int> dict;
        for (auto &num: arr) {
            dict[num]++;
        }

        std::unordered_set<int> freq;
        for (auto &p: dict) {
            if (freq.find(p.second) != freq.end()) {
                return false;
            }
            freq.emplace(p.second);
        }
        return true;
    }
};

int main() {
    vector<vector<int>> testCases {
        { 1,2,2,1,1,3 },
        { 1,2 },
        { -3,0,1,-3,1,1,1,-3,10,0 }
    };
    for (auto &testCase: testCases) {
        cout << boolalpha << Solution().uniqueOccurrences(testCase) << endl;
    }
    return 0;
}
