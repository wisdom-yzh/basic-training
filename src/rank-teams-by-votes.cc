#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    string rankTeams(vector<string> &votes) {
        map<char, vector<int>> mp;
        for (auto &v: votes){
            for(int i = 0; i < v.size();i++){
                mp[v[i]].resize(v.size());
                mp[v[i]][i]++;
            }
        }
        string res = votes[0];
        sort(res.begin(), res.end(), [&](char a, char b) {
            return mp[a]> mp[b] || (mp[a] == mp[b] && a < b);
        });
        return res;
    }
};

int main() {
    vector<vector<string>> testCases {
        {"ABC","ACB","ABC","ACB","ACB"},
        {"WXYZ","XYZW"},
        {"ZMNAGUEDSJYLBOPHRQICWFXTVK"},
        {"BCA","CAB","CBA","ABC","ACB","BAC"}
    };
    for (auto &testCase: testCases) {
        cout << Solution().rankTeams(testCase) << endl;
    }
    return 0;
}
