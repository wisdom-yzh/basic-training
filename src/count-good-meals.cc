#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    constexpr static uint64_t MOD = 1e9 + 7;

    int countPairs(vector<int>& deliciousness) {
        uint64_t res = 0;
        std::unordered_map<uint64_t, uint64_t> dict;
        for (const auto &num: deliciousness) {
            dict[num]++;
        }

        for (uint64_t i = 0; i <= 22; i++) {
            uint64_t x = (1L << i);
            for (const auto &[number, count]: dict) {
                if (x - number == number) {
                    res += count * (count - 1L);
                } else {
                    auto iter = dict.find(x - number);
                    if (iter != dict.end()) {
                        res += count * iter->second;
                    }
                }
            }
        }

        res = (res / 2L) % MOD;
        return static_cast<int>(res);
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> deliciousness = stringToIntegerVector(line);

        int ret = Solution().countPairs(deliciousness);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
