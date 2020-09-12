#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        const int64_t maxValue = std::max(*std::max_element(A.begin(), A.end()), *std::max_element(B.begin(), B.end()));
        auto hashPair = [&maxValue](const pair<int, int> &num) {
            return num.first + maxValue * num.second;
        };
        std::unordered_set<pair<int, int>, decltype(hashPair)> checked(A.size(), hashPair);
        int minRotations = -1;

        for (int i = 0; i < A.size(); i++) {
            if (checked.find(make_pair(A[i], 0)) == checked.end()) {
                getMinRotations(i, A, B, minRotations);
                checked.insert(make_pair(A[i], 0));
            }
            if (checked.find(make_pair(B[i], 1)) == checked.end()) {
                getMinRotations(i, B, A, minRotations);
                checked.insert(make_pair(B[i], 1));
            }
        }
        return minRotations;
    }

    void getMinRotations(int index, vector<int> &A, vector<int> &B, int &minRotations) {
        int minValue = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[index] == A[i]) {
                continue;
            } else if (A[index] == B[i]) {
                minValue++;
            } else {
                return;
            }
        }

        if (minRotations == -1) {
            minRotations = minValue;
        } else {
            minRotations = std::min(minRotations, minValue);
        }
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

        int ret = Solution().minDominoRotations(A, B);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
