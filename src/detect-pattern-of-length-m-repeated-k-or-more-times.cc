#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        for (int i = 0; i < arr.size() - m + 1; i++) {
            vector<int> pattern(next(arr.begin(), i), next(arr.begin(), i + m));

            int count = 0;
            for (int j = i + m; j < arr.size() - m + 1; ) {
                if (pattern == vector<int>(next(arr.begin(), j), next(arr.begin(), j + m))) {
                    j += m;
                    count++;
                    if (count >= k - 1) {
                        return true;
                    }
                } else {
                    break;
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

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> arr = stringToIntegerVector(line);
        getline(cin, line);
        int m = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);

        bool ret = Solution().containsPattern(arr, m, k);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
