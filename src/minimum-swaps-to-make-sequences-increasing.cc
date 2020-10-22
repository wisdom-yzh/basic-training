#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int swap = 1, origin = 0;

        for (int i = 1; i < A.size(); i++) {
            if (A[i] <= A[i - 1] || B[i] <= B[i - 1]) {
                int tmp = origin;
                origin = swap;
                swap = tmp + 1;
            } else if (A[i] <= B[i - 1] || B[i] <= A[i - 1]) {
                swap++;
            } else {
                int min = std::min(swap, origin);
                swap = min + 1;
                origin = min;
            }
        }

        return std::min(swap, origin);
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
        getline(cin, line);
        vector<int> B = stringToIntegerVector(line);

        int ret = Solution().minSwap(A, B);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
