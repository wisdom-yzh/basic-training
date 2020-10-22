#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) {
            return 0;
        }
        vector<vector<int>> num(A.size(), std::move(vector<int>(A.size(), -1)));
        vector<vector<int>> diff(A.size(), std::move(vector<int>(A.size(), std::numeric_limits<int>::max())));
        return numberOfArithmeticSlices(A, 0, A.size() - 1, num, diff);
    }

    int numberOfArithmeticSlices(vector<int> &A, int p, int q,
            vector<vector<int>> &num, vector<vector<int>> &diff) {
        if (num[p][q] != -1) {
            return num[p][q];
        }

        if (p == q) {
            num[p][q] = 0;
            diff[p][q] = 0;
            return num[p][q];
        }

        if (p + 1 == q) {
            num[p][q] = 0;
            diff[p][q] = A[q] - A[p];
            return num[p][q];
        }

        num[p][q] = numberOfArithmeticSlices(A, p + 1, q, num, diff) +
            numberOfArithmeticSlices(A, p, q - 1, num, diff) -
            numberOfArithmeticSlices(A, p + 1, q - 1, num, diff);

        if (q - p >= 2) {
            if (diff[p + 1][q] != std::numeric_limits<int>::max() &&
                diff[p][q - 1] != std::numeric_limits<int>::max() &&
                diff[p + 1][q] == diff[p][q - 1]) {
                diff[p][q] = diff[p + 1][q];
                num[p][q]++;
            }
        }

        return num[p][q];
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
        
        int ret = Solution().numberOfArithmeticSlices(A);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
