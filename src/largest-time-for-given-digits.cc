#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        vector<int> maxValue { 0, 0, 0, 0 };
        if (!dfs(A, 0, maxValue)) {
            return "";
        }
        stringstream ss;
        ss << maxValue[0] << maxValue[1] << ":" << maxValue[2] << maxValue[3];
        return ss.str();
    }

    bool dfs(vector<int> &A, int idx, vector<int> &maxValue) {
        bool result = false;
        if (idx == 3 && time(A) >= time(maxValue)) {
            maxValue = A;
            return true;
        }

        for (int i = idx; i < 4; i++) {
            if ((idx == 0 && A[i] <= 2) ||
                (idx == 1 && ((A[idx - 1] == 2 && A[i] <= 3) || A[idx - 1] < 2)) ||
                (idx == 2 && A[i] <= 5)) {
                std::swap(A[idx], A[i]);
                result |= dfs(A, idx + 1, maxValue);
                std::swap(A[idx], A[i]);
            }
        }
        return result;
    }

    int time(vector<int> &nums) {
        return 60 * (nums[0] * 10 + nums[1]) + nums[2] * 10 + nums[3];
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

        string ret = Solution().largestTimeFromDigits(A);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
