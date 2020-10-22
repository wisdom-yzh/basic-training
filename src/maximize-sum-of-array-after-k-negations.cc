#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int sum = 0, partASum = 0, minAbs = std::numeric_limits<int>::max();
        vector<int> partA;

        for (const auto &num: A) {
            if (num < 0) {
                partA.push_back(num);
                partASum += num;
            }
            minAbs = std::min(std::abs(num), minAbs);
            sum += num;
        }

        if (partA.size() >= K) {
            std::sort(partA.begin(), partA.end());
            for (int i = 0; i < K; i++) {
                sum += (-2 * partA[i]);
            }
            return sum;
        }

        sum += (-2 * partASum);
        if ((K - partA.size()) % 2 == 0) {
            return sum;
        }
        sum += (-2 * std::abs(minAbs));
        return sum;
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

        int ret = Solution().largestSumAfterKNegations(A, K);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
