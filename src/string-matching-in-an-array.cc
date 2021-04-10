#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        std::sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() > b.size();
        });

        vector<string> res;

        for (auto iter = words.begin(); iter != words.end(); iter++) {
            for (auto nextIter = next(iter); nextIter != words.end(); ) {
                if (iter->find(*nextIter, 0) != string::npos) {
                    res.push_back(move(*nextIter));
                    nextIter = words.erase(nextIter);
                } else {
                    nextIter++;
                }
            }
        }

        return res;
    }
};

int main() {
    vector<vector<string>> testCases {
        {"mass","as","hero","superhero"},
        {"leetcode","et","code"},
        {"blue","green","bu"}
    };
    for (auto &testCase: testCases) {
        for (auto &item: Solution().stringMatching(testCase)) {
            cout << item << ' ';
        }
        cout << endl;
    }
    return 0;
}
