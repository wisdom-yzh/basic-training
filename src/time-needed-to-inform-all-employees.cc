#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res = 0;
        queue<pair<int, int>> q;

        vector<vector<int>> children(n, vector<int>(0));
        for (int i = 0; i < manager.size(); i++) {
            if (manager[i] == -1) {
                continue;
            }
            children[manager[i]].push_back(i);
        }

        q.push(make_pair(headID, 0));

        while (!q.empty()) {
            int head, num;
            tie(head, num) = q.front();

            res = std::max(res, num);

            for (auto &c: children[head]) {
                q.push(make_pair(c, num + informTime[head]));
            }

            q.pop();
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

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int headID = stringToInteger(line);
        getline(cin, line);
        vector<int> manager = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> informTime = stringToIntegerVector(line);

        int ret = Solution().numOfMinutes(n, headID, manager, informTime);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
