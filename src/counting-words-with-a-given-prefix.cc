#include <bits/stdc++.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int prefixCount(vector<string> &words, string pref) {
    int count = 0;
    for (auto &word : words) {
      if (word.size() < pref.size()) {
        continue;
      }
      bool prefix = true;
      for (int i = 0; i < pref.size() && prefix; i++) {
        if (word[i] != pref[i]) {
          prefix = false;
        }
      }
      if (prefix) {
        count++;
      }
    }
    return count;
  }
};

int main(int argc, char *argv[]) {
  std::vector<pair<vector<string>, string>> testCases{
      {{"pay", "attention", "practice", "attend"}, "at"},
      {{"leetcode", "win", "loops", "success"}, "code"},
  };
  for (auto &[words, pref] : testCases) {
    cout << Solution().prefixCount(words, pref) << endl;
  }
  return 0;
}
