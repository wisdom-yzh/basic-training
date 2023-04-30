#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int countWords(vector<string> &words1, vector<string> &words2) {
    std::map<std::string, int> map1, map2;
    for (auto &w : words1) {
      map1[w]++;
    }
    for (auto &w : words2) {
      map2[w]++;
    }

    int res{0};
    for (auto &[k, v] : map1) {
      if (v == 1 && map2[k] == 1) {
        res++;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<vector<string>, vector<string>>> testCases{
      {{"leetcode", "is", "amazing", "as", "is"},
       {"amazing", "leetcode", "is"}},
      {{"b", "bb", "bbb"}, {"a", "aa", "aaa"}},
      {{"a", "ab"}, {"a", "a", "a", "ab"}},
  };
  for (auto &[w1, w2] : testCases) {
    cout << Solution().countWords(w1, w2) << endl;
  }
  return 0;
}
