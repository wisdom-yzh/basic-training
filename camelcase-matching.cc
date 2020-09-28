#include <vector>
#include <string>
#include <iostream>
#include <regex>
using namespace std;

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        string rePattern = "([a-z]*)";
        for (auto &ch: pattern) {
            rePattern += std::string { ch } + "([a-z]*)";
        }
        std::regex re(rePattern);

        vector<bool> results;
        for (const auto &query: queries) {
            results.push_back(regex_match(query, re));
        }

        return results;
    }
};

int main() {
    vector<pair<vector<string>, string>> testCases {
        { { "FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack" }, "FB" },
        { { "FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack" }, "FoBa" },
        { { "FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack" }, "FoBaT" }
    };
    for (auto &testCase: testCases) {
        for (const auto &res: Solution().camelMatch(testCase.first, testCase.second)) {
            cout << boolalpha << res << ' ';
        }
        cout << endl;
    }
    return 0;
}
