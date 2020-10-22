#include <iostream>
#include <cassert>
#include <string>
using namespace std;

class Solution {
    public:
        string predictPartyVictory(string senate) {
            int dire = 0, radiant = 0;
            for (const auto &ch: senate) {
                if (ch == 'D') {
                    dire++;
                } else {
                    radiant++;
                }
            }

            while (true) {
                if (dire > radiant * 2) {
                    return "Dire";
                }
                if (radiant > dire * 2) {
                    return "Radiant";
                }

                for (int i = 0; i < senate.size(); i++) {
                    auto & ch  = senate[i];
                    if (ch == ' ') continue;;

                    for (int j = i + 1; j != i; j++) {
                        if (j == senate.size()) {
                            j = 0;
                        }
                        if (senate[j] == ch || senate[j] == ' ') {
                            continue;
                        }
                        senate[j] == 'R' ? radiant-- : dire--;
                        senate[j] = ' ';
                        break;
                    }
                }
            }
            return "";
        }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string senate = stringToString(line);

        string ret = Solution().predictPartyVictory(senate);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
