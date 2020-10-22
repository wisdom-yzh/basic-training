#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int result = 0;
        std::map<int, int> maxProbit;

        for (int i = 0; i < difficulty.size(); i++) {
            maxProbit[difficulty[i]] =  std::max(maxProbit[difficulty[i]], profit[i]);
        }

        int probit = 0;
        for (auto iter = maxProbit.begin(); iter != maxProbit.end(); iter++) {
            if (iter->second > probit) {
                probit = iter->second;
            } else {
                iter->second = probit;
            }
        }

        for (const auto &w: worker) {
            auto p = maxProbit.find(w);
            if (p == maxProbit.end()) {
                p = maxProbit.lower_bound(w);
                if (p == maxProbit.begin()) {
                    continue;
                }
                p--;
            }
            result += p->second;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> difficulty = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> profit = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> worker = stringToIntegerVector(line);

        int ret = Solution().maxProfitAssignment(difficulty, profit, worker);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
