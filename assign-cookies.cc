#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end(), std::greater<int>());
        std::sort(s.begin(), s.end(), std::greater<int>());

        int result = 0;
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] > s[j]) {
                i++;
            } else {
                i++;
                j++;
                result++;
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
        vector<int> g = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> s = stringToIntegerVector(line);

        int ret = Solution().findContentChildren(g, s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
