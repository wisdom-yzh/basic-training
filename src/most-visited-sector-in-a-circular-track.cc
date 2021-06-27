#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> res;

        if (rounds.front() > rounds.back()) {
            for (int i = 1; i <= rounds.back(); i++) {
                res.push_back(i);
            }
            for (int i = rounds.front(); i <= n; i++) {
                res.push_back(i);
            }
        } else {
            for (int i = rounds.front(); i <= rounds.back(); i++) {
                res.push_back(i);
            }
        }

        return res;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

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
        int n = stringToInteger(line);
        getline(cin, line);
        vector<int> rounds = stringToIntegerVector(line);

        vector<int> ret = Solution().mostVisited(n, rounds);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
