#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        const int modulo = 1e9 + 7;
        vector<int> sum(A.size(), 0);
        int result = 0;
        std::vector<pair<int, int>> S;

        for (int i = 0; i < A.size(); i++) {
            while (!S.empty() && S.back().first > A[i]) {
                S.pop_back();
            }

            if (S.empty()) {
                sum[i] = A[i] * (i + 1);
            } else {
                sum[i] = sum[S.back().second] + A[i] * (i - S.back().second);
            }

            S.push_back({ A[i], i });
            result = (result + sum[i]) % modulo;
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
        vector<int> A = stringToIntegerVector(line);

        int ret = Solution().sumSubarrayMins(A);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
