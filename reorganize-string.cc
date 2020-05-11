#include <string>
#include <algorithm>
#include <iostream>
#include <array>
#include <map>
#include <cassert>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        std::array<int, 26> arr;
        arr.fill(0);

        int maxCount = 0, maxAlphabet = -1;

        for (const auto &ch: S) {
            if (++arr[ch - 'a'] > maxCount) {
                maxCount = arr[ch - 'a'];
                maxAlphabet = ch - 'a';
            }
        }

        if ((S.size() + 1) / 2 < maxCount) {
            return "";
        }

        std::multimap<int, char> dict;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > 0) {
                dict.emplace(arr[i], i + 'a');
            }
        }

        string res;
        for (auto &item: dict) {
            if (res.empty()) {
                res.resize(item.first, item.second);
                continue;
            }
            string q(res);
            string p(item.first, item.second);

            res = "";
            int size = std::max(p.size(), q.size());
            for (int i = 0; i < size; i++) {
                if (i < p.size()) {
                    res += p[i];
                }
                if (i < q.size()) {
                    res += q[i];
                }
            }
        }

        return res;
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
        string S = stringToString(line);

        string ret = Solution().reorganizeString(S);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
