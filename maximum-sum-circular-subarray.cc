#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if (A.empty()) {
            return 0;
        }

        int accSum = A[0], accMinSum = A[0], minValue = A[0], maxValue = A[0], sum = A[0];
        for (int i = 1; i < A.size(); i++) {
            sum += A[i];
            if (accSum > 0) {
                accSum += A[i];
            } else {
                accSum = A[i];
            }
            maxValue = std::max(maxValue, accSum);
            if (accMinSum > 0) {
                accMinSum = A[i];
            } else {
                accMinSum += A[i];
            }
            minValue = std::min(minValue, accMinSum);
        }

        if (maxValue < 0) {
            return maxValue;
        }
        return std::max(maxValue, sum - minValue);
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

        int ret = Solution().maxSubarraySumCircular(A);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
