#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> s(forbidden.begin(), forbidden.end());
        queue<tuple<bool, int, int>> q;
        q.push(make_tuple(false, 0, 0));

        while (!q.empty()) {
            auto &[back, pos, step] = q.front();

            if (pos == x) {
                return step;
            }

            if (s.find(pos + a) == s.end() && pos + a <= 6000) {
                q.push(make_tuple(false, pos + a, step + 1));
                s.insert(pos + a);
            }

            if (pos - b >= 0 && s.find(pos - b) == s.end() && !back) {
                q.push(make_tuple(true, pos - b, step + 1));
            }

            q.pop();
        }

        return -1;
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
        vector<int> forbidden = stringToIntegerVector(line);
        getline(cin, line);
        int a = stringToInteger(line);
        getline(cin, line);
        int b = stringToInteger(line);
        getline(cin, line);
        int x = stringToInteger(line);

        int ret = Solution().minimumJumps(forbidden, a, b, x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
