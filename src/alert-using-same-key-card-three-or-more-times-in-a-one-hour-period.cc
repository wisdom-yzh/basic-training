#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int convertTime(const string &t) {
        return std::stoi(t.substr(0, 2)) * 60 + std::stoi(t.substr(3));
    }

    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        vector<pair<string, int>> names;
        for (int i = 0; i < keyName.size(); i++) {
            names.push_back({ keyName[i], convertTime(keyTime[i]) });
        }

        std::sort(names.begin(), names.end(), [] (pair<string, int> &n1, pair<string, int> &n2) {
            if (n1.first == n2.first) {
                return n1.second < n2.second;
            }
            return n1.first < n2.first;
        });

        vector<string> res;
        for (int i = 2; i < names.size(); i++) {
            if (names[i].first == names[i - 2].first &&
                names[i].second > names[i - 1].second &&
                names[i].second - names[i - 2].second <= 60 &&
                std::find(res.begin(), res.end(), names[i].first) == res.end()) {
                res.push_back(names[i].first);
            }
        }
        return res;
    }
};

int main() {
    vector<pair<vector<string>, vector<string>>> testCases {
        {
            {"daniel","daniel","daniel","luis","luis","luis","luis"},
            {"10:00","10:40","11:00","09:00","11:00","13:00","15:00"},
        },
        {
            {"alice","alice","alice","bob","bob","bob","bob"},
            {"12:01","12:00","18:00","21:00","21:20","21:30","23:00"},
        },
        {
            {"john","john","john"},
            {"23:58","23:59","00:01"},
        },
        {
            {"leslie","leslie","leslie","clare","clare","clare","clare"},
            {"13:00","13:20","14:00","18:00","18:51","19:30","19:49"},
        }
    };
    for (auto &[name, time]: testCases) {
        for (auto &name: Solution().alertNames(name, time)) {
            cout << name << ',';
        }
        cout << endl;
    }
    return 0;
}
