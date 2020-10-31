#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <limits>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<vector<int>> memo;

    int mctFromLeafValues(vector<int>& arr) {
        memo.assign(arr.size(), vector<int>(arr.size(), -1));
        return recurstiveMaxValue(arr, 0, arr.size() - 1);
    }

    int recurstiveMaxValue(vector<int> &arr, int i, int j) {
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (i == j) {
            return 0;
        }

        if (j == i + 1) {
            return arr[i] * arr[j];
        }

        int minValue = std::numeric_limits<int>::max();
        for (int k = i; k < j; k++) {
            minValue = std::min(
                minValue,
                *std::max_element(next(arr.begin(), i), next(arr.begin(), k + 1)) *
                *std::max_element(next(arr.begin(), k + 1), next(arr.begin(), j + 1)) +
                recurstiveMaxValue(arr, i, k) +
                recurstiveMaxValue(arr, k + 1, j)
            );
        }

        memo[i][j] = minValue;
        return minValue;
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
        vector<int> arr = stringToIntegerVector(line);

        int ret = Solution().mctFromLeafValues(arr);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
