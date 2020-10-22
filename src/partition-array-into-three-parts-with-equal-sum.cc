#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = std::accumulate(A.begin(), A.end(), 0);

        if (sum % 3 != 0) {
            return false;
        }

        int goal = sum / 3;
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < A.size() - 2; i++) {
            sum1 += A[i];
            if (sum1 == goal) {
                sum2 = 0;
                for (int j = i + 1; j < A.size() - 1; j++) {
                    sum2 += A[j];
                    if (sum2 == goal) {
                        return true;
                    }
                }
            }
        }

        return false;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);

        bool ret = Solution().canThreePartsEqualSum(A);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
