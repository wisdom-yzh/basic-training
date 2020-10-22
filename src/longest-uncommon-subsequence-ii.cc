#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(pair<string,int> &a, pair<string,int> &b) {
    return a.first.size() > b.first.size();
}

bool isS1subsOfS2 (string &s1, string &s2) {
    int j = 0, i = 0;
    for(; i < s1.size(); ++i) {
        while(j < s2.size() && s1[i] != s2[j]) {
            ++j;
        }

        if(j == s2.size()) {
            return false;
        }
        ++j;
    }
    return true;
}

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        unordered_map<string,int> m;
        for (int i = 0; i < strs.size(); ++i) {
          ++m[strs[i]];
        }
        vector<pair<string,int>> v;
        for (auto it = m.begin(); it != m.end(); ++it) {
           v.push_back(*it);
        }
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < v.size(); ++i) {
           if (v[i].second == 1) {
               int j = 0;
               for(; j < i; ++j)
                 if(isS1subsOfS2(v[i].first,v[j].first))
                     break;
               if(j == i) return v[i].first.size();
           }
        }
        return -1;
    }
};

int main() {
    vector<string> strs { "aba", "cdc", "eae" };
    std::cout << Solution().findLUSlength(strs);
    return 0;
}
