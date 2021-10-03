#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> people(scores.size());
        for (int i = 0; i < scores.size(); i++) {
            people[i] = { ages[i], scores[i] };
        }

        std::sort(people.begin(), people.end(), [](pair<int, int> &p1, pair<int, int> &p2) {
            return p1.first == p2.first ?
                p1.second < p2.second :
                p1.first < p2.first;
        });

        vector<int> maxScore(people.size(), 0);
        int res = 0;
        for(int i = 0; i < people.size(); i++) {
            maxScore[i] = people[i].second;
            for(int j = 0; j < i; j++) {
                if (people[j].second <= people[i].second) {
                    maxScore[i] = std::max(maxScore[i], maxScore[j] + people[i].second);
                }
            }
            res = std::max(res, maxScore[i]);
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
        vector<int> scores = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> ages = stringToIntegerVector(line);

        int ret = Solution().bestTeamScore(scores, ages);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
