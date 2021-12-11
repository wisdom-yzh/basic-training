#include <vector>
#include <tuple>
#include <set>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        std::set<int> s;

        for (int i = 0; i < friendships.size(); i++) {
            auto &lang1 = languages[friendships[i][0] - 1];
            auto &lang2 = languages[friendships[i][1] - 1];
            bool sameLang = false;

            for (int i = 0; i < lang1.size(); i++) {
                for (int j = 0; j < lang2.size(); j++) {
                    if (lang1[i] == lang2[j]) {
                        sameLang = true;
                        break;
                    }
                }
                if (sameLang) {
                    break;
                }
            }

            if (!sameLang) {
                s.emplace(friendships[i][0] - 1);
                s.emplace(friendships[i][1] - 1);
            }
        }

        std::map<int, int> dict;
        for (const auto &p: s) {
            for (auto &lang: languages[p]) {
                dict[lang]++;
            }
        }

        int most = 0;
        for (auto &p: dict) {
            most = std::max(most, p.second);
        }
        return s.size() - most;
    }
};

int main() {
    vector<tuple<int, vector<vector<int>>, vector<vector<int>>>> testCases {
        { 2, {{1},{2},{1,2}}, {{1,2},{1,3},{2,3}} },
        { 3, {{2},{1,3},{1,2},{3}}, {{1,4},{1,2},{3,4},{2,3}} }
    };
    for (auto &[n, languages, friendships]: testCases) {
        cout << Solution().minimumTeachings(n, languages, friendships) << endl;
    }
}
