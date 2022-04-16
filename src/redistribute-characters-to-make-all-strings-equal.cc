#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        std::array<int, 26> arr;
        std::fill(arr.begin(), arr.end(), 0);

        for (auto &word: words) {
            for (auto &ch: word) {
                arr[ch - 'a']++;
            }
        }

        for (auto &x: arr) {
            if ((x % words.size()) != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<string>> testCases {
        {"abc","aabc","bc"},
        {"ab","a"}
    };

    for (auto &testCase: testCases) {
        cout << boolalpha << Solution().makeEqual(testCase) << endl;
    }
    return 0;
}
