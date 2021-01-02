#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        string res;
        int i = 0;

        while (true) {
            if (i <= s.size() - 3 && s[i + 2] == '#') {
                res.push_back('a' + std::stoi(s.substr(i, 2)) - 1);
                i += 3;
            } else {
                res.push_back('a' + s[i] - '0' - 1);
                i++;
            }

            if (i >= s.size()) {
                break;
            }
        }

        return res;
    }
};

int main() {
    vector<string> testCases {
        "10#11#12",
        "1326#",
        "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#",
    };
    for (auto &testCase: testCases) {
        cout << Solution().freqAlphabets(testCase) << endl;
    }
    return 0;
}
