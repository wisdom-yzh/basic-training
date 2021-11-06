#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<pair<int, int>> score;
        for (int i = 0; i < aliceValues.size(); i++) {
            score.emplace_back(aliceValues[i] + bobValues[i], i);
        }

        std::sort(score.begin(), score.end(), [] (auto &a, auto &b) {
            return a.first > b.first;
        });

        int aliceSum = 0, bobSum = 0;
        for (int i = 0; i < score.size(); i++) {
            if (i % 2 == 0) {
                aliceSum += aliceValues[score[i].second];
            } else {
                bobSum += bobValues[score[i].second];
            }
        }

        return aliceSum == bobSum ? 0 : aliceSum > bobSum ? 1 : -1;
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
        vector<int> aliceValues = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> bobValues = stringToIntegerVector(line);

        int ret = Solution().stoneGameVI(aliceValues, bobValues);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
