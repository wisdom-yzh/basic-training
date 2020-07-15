#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        uint32_t mask = 0;
        for (const auto &num: A) {
            mask |= num;
        }

        std::unordered_set<uint32_t> s { mask };
        for (int i = 0; i < A.size(); i++) {
            uint32_t num = 0;
            for (int j = i; j >= 0; j--) {
                num |= A[j];
                if (num == mask) {
                    break;
                }
                s.emplace(num);
            }
        }
        return s.size();
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

        int ret = Solution().subarrayBitwiseORs(A);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
