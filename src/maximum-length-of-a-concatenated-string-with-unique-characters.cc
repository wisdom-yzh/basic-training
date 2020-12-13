#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int recursion(vector<string> &arr, int i, vector<bool> &table, int value) {
        if (i == arr.size()) {
            return value;
        }

        int maxValue = value;

        bool canUse = true;
        for (auto &ch: arr[i]) {
            if (table[ch - 'a']) {
                canUse = false;
                break;
            }
        }

        if (canUse) {
            for (auto &ch: arr[i]) {
                table[ch - 'a'] = true;
            }
            maxValue = std::max(maxValue, recursion(arr, i + 1, table, value + arr[i].size()));
            for (auto &ch: arr[i]) {
                table[ch - 'a'] = false;
            }
        }

        maxValue = std::max(maxValue, recursion(arr, i + 1, table, value));
        return maxValue;
    }

    int maxLength(vector<string>& arr) {
        for (auto iter = arr.begin(); iter != arr.end();) {
            vector<bool> chs(26, false);
            bool erased = false;
            for (auto &ch: *iter) {
                if (chs[ch - 'a']) {
                    iter = arr.erase(iter);
                    erased = true;
                    break;
                }
                chs[ch - 'a'] = true;
            }
            if (!erased) {
                iter++;
            }
        }
        vector<bool> table(26, false);
        return recursion(arr, 0, table, 0);
    }
};

int main() {
    vector<vector<string>> testCases {
        { "yy","bkhwmpbiisbldzknpm" },
        { "un","iq","ue" },
        { "cha","r","act","ers" },
        { "abcdefghijklmnopqrstuvwxyz" }
    };
    for (auto &testCase: testCases) {
        cout << Solution().maxLength(testCase) << endl;
    }
    return 0;
}
