#include <vector>
#include <numeric>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        const uint32_t MAGIC_NUM = std::pow(10, 9) + 7;
        std::map<int, int> dict;

        std::sort(A.begin(), A.end());
        for (const auto &num: A) {
            dict[num] = 1;
        }

        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (A[i] % A[j] == 0) {
                    dict[A[i]] = (dict[A[i]] + (uint64_t)dict[A[j]] * dict[A[i] / A[j]]) % MAGIC_NUM;
                }
            }
        }

        return std::accumulate(dict.begin(), dict.end(), 0, [&](int acc, const std::pair<int, int> &p) {
            return (acc + p.second) % MAGIC_NUM;
        });
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
        vector<int> A = stringToIntegerVector(line);

        int ret = Solution().numFactoredBinaryTrees(A);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
