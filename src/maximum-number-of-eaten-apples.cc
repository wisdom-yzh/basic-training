#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int res = 0, lastDay = 0;
        for (int i = 0; i < days.size(); i++) {
            lastDay = std::max(i + days[i], lastDay);
        }

        vector<int> appleDay(lastDay, 0);

        for (int i = 0; i < lastDay; i++) {
            if (i < apples.size() && apples[i] > 0) {
                appleDay[i + days[i] - 1] += apples[i];
            }

            int idx = i;
            while (idx < lastDay && appleDay[idx] == 0) {
                idx++;
            }

            if (idx != lastDay) {
                appleDay[idx]--;
                res++;
            }
        }

        return res;
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
        vector<int> apples = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> days = stringToIntegerVector(line);

        int ret = Solution().eatenApples(apples, days);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
