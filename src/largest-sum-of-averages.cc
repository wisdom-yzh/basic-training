#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        std::unordered_map<uint64_t, double> memo;
        return this->recursiveDp(A, 0, A.size() - 1, K, memo);
    }

    double recursiveDp(vector<int> &A, int i, int j, int k, std::unordered_map<uint64_t, double> &memo) {
        uint64_t N = 10001 * (101 * k + j) + i;
        auto p = memo.find(N);
        if (p != memo.end()) {
            return p->second;
        }

        double result = 0;

        if (k == 1) {
            for (int m = i; m <= j; m++) {
                result += A[m];
            }
            result /= (j - i + 1.0);
        } else {
            for (int m = i; m < j; m++) {
                result = std::max(result, this->recursiveDp(A, i, m, k - 1, memo) + this->recursiveDp(A, m + 1, j, 1, memo));
            }
        }

        memo.emplace(N, result);
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
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        int K = stringToInteger(line);

        double ret = Solution().largestSumOfAverages(A, K);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
