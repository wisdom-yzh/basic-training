#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        unordered_map<string, bitset<512>> nmap;
        vector<int> ret;

        for (int i = 0; i < favoriteCompanies.size(); i++) {
            for(auto &word: favoriteCompanies[i]) {
                nmap[word].set(i);
            }
        }

        for (int i = 0; i < favoriteCompanies.size(); i++) {
            auto bits = nmap[favoriteCompanies[i][0]];
            for(int j = 1; j < favoriteCompanies[i].size(); j++) {
                bits &= nmap[favoriteCompanies[i][j]];
            }
            if(bits.count() <= 1) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};

int main() {
    vector<vector<vector<string>>> testCases {
        {{"leetcode","google","facebook"},{"google","microsoft"},{"google","facebook"},{"google"},{"amazon"}},
        {{"leetcode","google","facebook"},{"leetcode","amazon"},{"facebook","google"}},
        {{"leetcode"},{"google"},{"facebook"},{"amazon"}}
    };
    for (auto &testCase: testCases) {
        for (auto &x: Solution().peopleIndexes(testCase)) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
