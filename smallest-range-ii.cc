#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        if (A.size() <= 1) {
            return 0;
        }

        std::sort(A.begin(), A.end());
        int result = A[A.size() - 1] - A[0];

        for (int i = 0; i < A.size() - 1; i++) {
            int max = std::max(A[i] + K, A[A.size() - 1] - K);
            int min = std::min(A[0] + K, A[i + 1] - K);
            result = std::min(result, max - min);
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
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        int K = stringToInteger(line);

        int ret = Solution().smallestRangeII(A, K);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
