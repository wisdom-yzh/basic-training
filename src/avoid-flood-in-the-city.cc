#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        map<int, int> full;
        vector<int> result;
        set<int> s;

        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] != 0) {
                auto iter = full.find(rains[i]);
                if (iter != full.end()) {
                    auto x = s.upper_bound(iter->second);
                    if (x == s.end()) {
                        return {};
                    }
                    result[*x] = rains[i];
                    iter->second = i;
                    s.erase(x);
                } else {
                    full.emplace(rains[i], i);
                }

                result.push_back(-1);
                continue;
            }

            result.push_back(1);
            s.emplace(i);
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
        vector<int> rains = stringToIntegerVector(line);

        vector<int> ret = Solution().avoidFlood(rains);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
