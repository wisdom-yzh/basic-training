#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int result = 0;

        std::map<int, int> dict;
        for (auto &a: A) {
            for (auto &b: B) {
                if (dict.find(a + b) == dict.end()) {
                    dict[a + b] = 1;
                } else {
                    dict[a + b]++;
                }
            }
        }

        for (auto &c: C) {
            for (auto &d: D) {
                auto p = dict.find(-(c + d));
                if (p != dict.end()) {
                    result += p->second;
                }
            }
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> B = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> C = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> D = stringToIntegerVector(line);

        int ret = Solution().fourSumCount(A, B, C, D);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
