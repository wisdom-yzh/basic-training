#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int maxSize = 1, size = 1, prevDiff = 0;
        for (int i = 1; i < A.size(); i++) {
            int diff = A[i] - A[i - 1];
            if (diff == 0 || static_cast<int64_t>(prevDiff) * diff > 0L) {
                size = 1;
                prevDiff = 0;
                if (diff != 0) {
                    i--;
                }
                continue;
            }

            size++;
            prevDiff = diff;
            maxSize = std::max(maxSize, size);
        }

        return maxSize;
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

        int ret = Solution().maxTurbulenceSize(A);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
