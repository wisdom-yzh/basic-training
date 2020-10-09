#include <algorithm>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numTilePossibilities(string tiles) {
        std::unordered_set<string> dict;
        std::sort(tiles.begin(), tiles.end());
        do {
            for (auto i = 0; i < tiles.size(); i++) {
                dict.emplace(tiles.substr(i));
            }
        } while(std::next_permutation(tiles.begin(), tiles.end()));

        return dict.size();
    }
};

int main() {
    vector<string> testCases {
        "AAB",
        "AAABBC",
        "V"
    };
    for (auto &testCase: testCases) {
        cout << Solution().numTilePossibilities(testCase) << endl;
    }
    return 0;
}
