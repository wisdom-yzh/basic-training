#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.empty()) {
            return 0;
        }
        int sum = 0, F0 = 0, F1 = 0, maxValue = 0;
        const int N = A.size();
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            F0 += i * A[i];
        }
        maxValue = F0;
        for (int i = 0; i < N; i++) {
            F1 = F0 + sum - N * A[N - i - 1];
            maxValue = std::max(maxValue, F1);
            F0 = F1;
        }
        return maxValue;
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

        int ret = Solution().maxRotateFunction(A);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
