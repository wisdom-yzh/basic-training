#include <vector>
#include <string>
#include <set>
#include <iterator>
#include <limits>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> result;
        multiset<int> s;

        for (auto &word: words) {
            s.emplace(freq(word));
        }

        for (auto &word: queries) {
            result.push_back(std::distance(s.upper_bound(freq(word)), s.end()));
        }

        return result;
    }

    int freq(string &str) {
        int f = 0;
        char minCh = std::numeric_limits<char>::max();

        for (auto &ch: str) {
            if (ch < minCh) {
                f = 1;
                minCh = ch;
            } else if (ch == minCh) {
                f++;
            }
        }

        return f;
    }
};

int main() {
    vector<pair<vector<string>, vector<string>>> testCases {
        { {"cbd"}, {"zaaaz"} },
        { {"bbb","cc"}, {"a","aa","aaa","aaaa"} }
    };
    for (auto &testCase: testCases) {
        for (auto &num: Solution().numSmallerByFrequency(testCase.first, testCase.second)) {
            cout << num << ' ';
        }
        cout << endl;
    }
    return 0;
}
