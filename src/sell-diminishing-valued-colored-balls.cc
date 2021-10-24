#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    static constexpr uint64_t MOD = 1e9 + 7;

    int maxProfit(vector<int>& inventory, int orders) {
        std::priority_queue<int> q;
        std::unordered_map<int, int> dict;

        for (const auto &x: inventory) {
            if (++dict[x] == 1) {
                q.emplace(x);
            }
        }

        uint64_t result = 0;
        while (orders > 0) {
            uint64_t begin = q.top();
            q.pop();
            uint64_t end = q.empty() ? 0 : q.top();
            uint64_t n = begin - end;
            uint64_t count = n * dict[begin];

            if (orders >= count) {
                orders -= count;
                result = (result + n * (begin + end + 1l) / 2l * dict[begin]) % MOD;
                dict[end] += dict[begin];
            } else {
                n = orders / dict[begin];
                end = begin - n;
                uint64_t remain = orders % dict[begin];
                result = (result + n * (begin + end + 1l) / 2l * dict[begin] + remain * end) % MOD;
                break;
            }
        }

        return result;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> inventory = stringToIntegerVector(line);
        getline(cin, line);
        int orders = stringToInteger(line);

        int ret = Solution().maxProfit(inventory, orders);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
