#include <string>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <limits>
#include <tuple>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        stack<tuple<string, uint64_t, uint64_t>> str;

        string s = "";
        uint64_t num = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] >= '0' && S[i] <= '9') {
                num = 10 * num + (S[i] - '0');
                if (num > std::numeric_limits<int64_t>::max()) {
                    num = std::numeric_limits<int64_t>::max();
                }
            } else {
                if (num != 0) {
                    uint64_t totalNum = str.empty() ? 0 : std::get<2>(str.top());
                    totalNum = (totalNum + s.size()) * num;
                    str.push({ move(s), num, totalNum});
                    s = string { S[i] };
                    num = 0;
                } else {
                    s.push_back(S[i]);
                }
            }
        }

        if (!s.empty()) {
            uint64_t totalNum = 0;
            if (!str.empty()) {
                totalNum = std::get<2>(str.top());
            }
            totalNum = (totalNum + s.size()) * (num == 0 ? 1 : num);
            str.push({ move(s), num == 0 ? 1 : num, totalNum });
        }

        while (!str.empty()) {
            int totalNum, num;
            string s;
            std::tie(s, num, totalNum) = str.top();

            int segmentLength = totalNum / num;
            int segmentOffset = (K - 1) % segmentLength;
            int prevLength = segmentLength - s.size();
            if (segmentOffset >= prevLength) {
                return string { s[segmentOffset - prevLength] };
            }
            K = segmentOffset;
            str.pop();
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string S = stringToString(line);
        getline(cin, line);
        int K = stringToInteger(line);

        string ret = Solution().decodeAtIndex(S, K);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
