#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

class Solution {
public:
    static const int CATEGORY_SIZE = 7;
    static const int CATEGORY_TOTAL = 49;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        std::array<string, CATEGORY_TOTAL> dict;
        dict.fill("");

        for (const auto &item: allowed) {
            dict[calc(item)].push_back(item[2]);
        }

        return this->recursionTransition(bottom, dict);
    }

    inline int calc(const string &item) {
        return (item[0] - 'A') * CATEGORY_SIZE + (item[1] - 'A');
    }

    bool recursionTransition(const string &bottom, std::array<string, CATEGORY_TOTAL> &dict) {
        if (bottom.size() == 1) {
            return true;
        }

        vector<string> nextList(1, "");
        for (int i = 0; i < bottom.size() - 1; i++) {
            int idx = calc(bottom.substr(i, 2));
            if (dict[idx].empty()) {
                return false;
            }

            vector<string> tmpNextList;
            for (int j = 0; j < dict[idx].size(); j++) {
                for (auto nextStr: nextList) {
                    nextStr.push_back(dict[idx][j]);
                    tmpNextList.push_back(nextStr);
                }
            }
            nextList = std::move(tmpNextList);
        }

        for (const auto &nextStr: nextList) {
            if (recursionTransition(nextStr, dict)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    string bottom = "BCD";
    vector<string> allowed {"BCG", "CDE", "GEA", "FFF" };
    cout << Solution().pyramidTransition(bottom, allowed);
    return 0;
}
