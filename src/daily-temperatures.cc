#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        std::stack<int> stk;
        vector<int> result(T.size());

        for (int i = 0; i < T.size(); i++) {
            while (!stk.empty()) {
                auto top = stk.top();
                if (T[top] >= T[i]) {
                    break;
                }
                result[top] = i - top;
                stk.pop();
            }
            stk.push(i);
        }

        while (!stk.empty()) {
            T[stk.top()] = 0;
            stk.pop();
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
            length = list.size();
        }

    if (length == 0) {
            return "[]";
        }

    string result;
    for(int index = 0; index < length; index++) {
            int number = list[index];
            result += to_string(number) + ", ";
        }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> T = stringToIntegerVector(line);

        vector<int> ret = Solution().dailyTemperatures(T);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
