#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    string alphabetBoardPath(string target) {
        std::map<string, string> dict;

        for (char from = 'a'; from <= 'y'; from++) {
            for (char to = 'a'; to <= 'y'; to++) {
                int fromRow = static_cast<int>(from - 'a') / 5;
                int fromCol = static_cast<int>(from - 'a') % 5;
                int toRow = static_cast<int>(to - 'a') / 5;
                int toCol = static_cast<int>(to - 'a') % 5;

                if (toRow - fromRow > 0) {
                    for (int i = fromRow; i < toRow; i++) {
                        dict[to_string(from) + to_string(to)] += "D";
                        dict[to_string(to) + to_string(from)] += "U";
                    }
                } else {
                    for (int i = fromRow; i < toRow; i++) {
                        dict[to_string(from) + to_string(to)] += "U";
                        dict[to_string(to) + to_string(from)] += "D";
                    }
                }

                if (toCol - fromCol > 0) {
                    for (int i = fromCol; i < toCol; i++) {
                        dict[to_string(from) + to_string(to)] += "R";
                        dict[to_string(to) + to_string(from)] += "L";
                    }
                } else {
                    for (int i = fromCol; i < toCol; i++) {
                        dict[to_string(from) + to_string(to)] += "L";
                        dict[to_string(to) + to_string(from)] += "R";
                    }
                }
            }
        }

        string result;
        char from = 'a';
        for (auto &ch: target) {
            if (ch == 'z') {
                if (from == 'z') {
                    result += "!";
                } else {
                    result += dict[to_string(from) + to_string('u')] + "D!";
                }
            } else {
                if (from == 'z') {
                    result += "U" + dict[to_string('u') + to_string(ch)] + "!";
                } else {
                    result += dict[to_string(from) + to_string(ch)] + "!";
                }
            }
            from = ch;
        }
        return result;
    }
};

int main() {
    vector<string> testCases {
        "leet",
        "code",
        "zdz",
    };
    for (auto &testCase: testCases) {
        cout << Solution().alphabetBoardPath(testCase) << endl;
    }
    return 0;
}
