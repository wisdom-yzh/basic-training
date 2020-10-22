#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        std::sort(A.begin(), A.end(), [](int &a, int &b) {
            return std::abs(a) < std::abs(b);
        });

        std::unordered_map<int, int> s;
        for (const auto &num: A) {
            s[num]++;
        }

        for (int i = 0; i < A.size(); i++) {
            auto iter = s.find(A[i]);
            if (iter == s.end() || iter->second == 0) {
                continue;
            }

            auto nextIter = s.find(A[i] * 2);
            if (nextIter == s.end() || nextIter->second == 0) {
                return false;
            }
            iter->second--;
            nextIter->second--;
        }

        return true;
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

        bool ret = Solution().canReorderDoubled(A);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
