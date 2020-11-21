#include <vector>
#include <string>
#include <iostream>
#include <tuple>
#include <array>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> result;
        vector<array<int, 26>> prefixSum;

        array<int, 26> cnt;
        cnt.fill(0);
        cnt[s[0] - 'a']++;

        prefixSum.push_back(cnt);

        for (int i = 1; i < s.size(); i++) {
            array<int, 26> current = prefixSum[i - 1];
            current[s[i] - 'a']++;
            prefixSum.push_back(current);
        }

        std::transform(queries.begin(), queries.end(), std::back_inserter(result), [&] (vector<int> &query) {
            size_t left = query[0], right = query[1], k = query[2];
            array<int, 26> cnt;

            if (left == 0) {
                for (int i = 0; i < 26; i++) {
                    cnt[i] = prefixSum[right][i] % 2;
                }
            } else {
                for (int i = 0; i < 26; i++) {
                    cnt[i] = (prefixSum[right][i] - prefixSum[left - 1][i]) % 2;
                }
            }

            int maxK = 0;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] != 0) {
                    maxK++;
                }
            }

            if (((right - left + 1) % 2) == 0) {
                return maxK <= (k * 2);
            }

            return (maxK - 1) <= (k * 2);
        });

        return result;
    }
};

int main() {
    vector<pair<string, vector<vector<int>>>> testCases {
        { "abcda", {{3,3,0},{1,2,0},{0,3,1},{0,3,2},{0,4,1}} }
    };
    for (auto &testCase: testCases) {
        for (const auto &item: Solution().canMakePaliQueries(testCase.first, testCase.second)) {
            cout << boolalpha << item << endl;
        }
    }
    return 0;
}
