#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<pair<int, int>> list;
        for (int i = 0; i < values.size(); i++) {
            list.push_back({ values[i], labels[i] });
        }
        std::sort(list.begin(), list.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.first > b.first;
        });

        int res = 0, count = 0;
        std::map<int, int> dict;

        for (int i = 0; i < list.size() && count < num_wanted; i++) {
            if (dict[list[i].second] == use_limit) {
                continue;
            }

            res += list[i].first;
            dict[list[i].second]++;
            count++;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> values = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> labels = stringToIntegerVector(line);
        getline(cin, line);
        int num_wanted = stringToInteger(line);
        getline(cin, line);
        int use_limit = stringToInteger(line);

        int ret = Solution().largestValsFromLabels(values, labels, num_wanted, use_limit);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
