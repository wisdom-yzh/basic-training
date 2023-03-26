#include <iostream>
#include <iterator>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
    std::map<int, int> itemMap;
    for (auto &item : items) {
      auto iter = itemMap.find(item[0]);
      if (iter == itemMap.end()) {
        itemMap.emplace(item[0], item[1]);
      } else if (iter->second < item[1]) {
        iter->second = item[1];
      }
    }

    int maxBeauty = 0;
    for (auto &x : itemMap) {
      if (maxBeauty > x.second) {
        x.second = maxBeauty;
      } else {
        maxBeauty = x.second;
      }
    }

    vector<int> result;
    for (auto &query : queries) {
      auto iter = itemMap.upper_bound(query);
      if (iter == itemMap.begin()) {
        result.push_back(0);
      } else {
        result.push_back(prev(iter)->second);
      }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<vector<vector<int>>, vector<int>>> testCases{
      {{{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}}, {1, 2, 3, 4, 5, 6}},
      {{{1, 2}, {1, 2}, {1, 3}, {1, 4}}, {1}},
      {{{10, 1000}}, {5}},
  };
  for (auto &[items, queries] : testCases) {
    for (auto &x : Solution().maximumBeauty(items, queries)) {
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}
