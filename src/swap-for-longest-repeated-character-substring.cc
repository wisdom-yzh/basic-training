#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxRepOpt1(string text) {
        vector<int> count(26, 0);
        vector<int> block(26, 0);
        vector<pair<char, int>> textStr;

        textStr.push_back({ text[0], 1 });
        block[text[0] - 'a']++;

        for (int i = 1; i < text.size(); i++) {
            if (text[i] == text[i - 1]) {
                textStr.back().second++;
            } else {
                textStr.push_back({ text[i], 1 });
                block[text[i] - 'a']++;
            }
        }

        for (int i = 0; i < textStr.size(); i++) {
            auto ch = textStr[i].first - 'a';

            if (i + 2 < textStr.size() &&
                textStr[i].first == textStr[i + 2].first &&
                textStr[i + 1].second == 1) {
                int currentCount = textStr[i].second + textStr[i + 2].second;
                if (block[ch] > 2) {
                    currentCount++;
                }
                count[ch] = std::max(count[ch], currentCount);
            } else {
                int currentCount = textStr[i].second;
                if (block[ch] > 1) {
                    currentCount++;
                }
                count[ch] = std::max(count[ch], currentCount);
            }
        }

        return *std::max_element(count.begin(), count.end());
    }
};

int main() {
    vector<string> testCases {
        "ababa",
        "aaabaaa",
        "aaabbaaa",
        "aaaaa",
        "abcdef"
    };
    for (auto &testCase: testCases) {
        cout << Solution().maxRepOpt1(testCase) << endl;
    }
    return 0;
}
