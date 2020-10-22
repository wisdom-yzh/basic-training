#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        vector<vector<string>> groups;

        for (const auto &s: A) {
            vector<string> g(2, "");
            for (int i = 0; i < s.size(); i += 2) {
                g[0].push_back(s[i]);
                if (i != s.size() - 1) {
                    g[1].push_back(s[i + 1]);
                }
            }
            std::sort(g[0].begin(), g[0].end());
            std::sort(g[1].begin(), g[1].end());

            if (std::find(groups.begin(), groups.end(), g) == groups.end()) {
                groups.push_back(g);
            }
        }

        return groups.size();
    }
};

int main() {
    vector<string> A {"abcd","cdab","cbad","xyzz","zzxy","zzyx"};
    cout << Solution().numSpecialEquivGroups(A);
    return 0;
}
