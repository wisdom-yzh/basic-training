#include <string>
#include <vector>
#include <functional>
#include <map>
using namespace std;

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        std::map<int, std::pair<int, string>, std::greater<int>> dict;
        for (int i = 0; i < indexes.size(); i++) {
            if (S.compare(indexes[i], sources[i].size(), sources[i]) == 0) {
                dict[indexes[i]] = make_pair(sources[i].size(), targets[i]);
            }
        }
        for (const auto &item: dict) {
            S.replace(item.first, item.second.first, item.second.second);
        }
        return S;
    }
};

int main() {
    return 0;
}
