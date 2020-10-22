#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
        if (A.empty()) {
            return 0;
        }
        bool mountainFound = false;
        int maxValue = 0, step = 0, length = 0;
        A.push_back(*(A.end() - 1));
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i - 1]) {
                if (step == 1) {
                    length++;
                } else if (step == -1 && mountainFound) {
                    maxValue = std::max(maxValue, length + 1);
                    mountainFound = false;
                    length = 1;
                } else {
                    length = 1;
                }
                step = 1;
            } else if (A[i] == A[i - 1]) {
                if (step == -1 && mountainFound) {
                    maxValue = std::max(maxValue, length + 1);
                    mountainFound = false;
                }
                length = 0;
                step = 0;
            } else {
                if (step == 1) {
                    mountainFound = true;
                }
                if (mountainFound) {
                    length++;
                }
                step = -1;
            }
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

        int ret = Solution().longestMountain(A);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
