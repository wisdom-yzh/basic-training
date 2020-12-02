#include <cassert>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> cost(s.size(), 0);

        for (int i = 0; i < s.size(); i++) {
            cost[i] = std::abs(s[i] - t[i]);
        }

        int mode = 1;
        int p = 0, q = p - 1, sum = 0, maxDist = 0;

        while (q < static_cast<int>(cost.size() - 1)) {
            if (mode == 1) {
                q++;
                sum += cost[q];
                if (sum <= maxCost) {
                    maxDist = std::max(q - p + 1, maxDist);
                } else {
                    mode = 0;
                }
            } else {
                sum -= cost[p];
                p++;
                if (sum <= maxCost) {
                    mode = 1;
                    maxDist = std::max(q - p + 1, maxDist);
                }
            }
        }

        return maxDist;
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
        string s = stringToString(line);
        getline(cin, line);
        string t = stringToString(line);
        getline(cin, line);
        int maxCost = stringToInteger(line);

        int ret = Solution().equalSubstring(s, t, maxCost);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
