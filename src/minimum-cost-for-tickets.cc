#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <limits>
using namespace std;

class Solution {
public:
    const static int TICKET_DAYS[3];

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        std::map<int, int> memo;
        std::set<int> daySet(days.begin(), days.end());
        return recursion(days.back(), daySet, costs, memo);
    }

    int recursion(int lastDay, set<int> &days, vector<int>& costs, std::map<int, int> &memo) {
        auto p = memo.find(lastDay);
        if (p != memo.end()) {
            return p->second;
        }

        if (lastDay <= 0) {
            return 0;
        }

        if (days.find(lastDay) == days.end()) {
            return recursion(lastDay - 1, days, costs, memo);
        }

        int result = std::numeric_limits<int>::max();
        for (int i = 0; i < costs.size(); i++) {
            result = std::min(recursion(lastDay - TICKET_DAYS[i], days, costs, memo) + costs[i], result);
        }

        memo.insert(make_pair(lastDay, result));
        return result;
    }
};

const int Solution::TICKET_DAYS[3] = { 1, 7, 30 };

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
        vector<int> days = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> costs = stringToIntegerVector(line);

        int ret = Solution().mincostTickets(days, costs);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
