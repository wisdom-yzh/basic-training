#include <bits/stdc++.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int wordCount(vector<string> &startWords, vector<string> &targetWords) {
    unordered_set<int> us;
    us.reserve(startWords.size());
    for (const string &word : startWords) {
      int num = 0;
      for (char c : word) {
        num |= (1 << (c - 'a'));
      }
      us.insert(num);
    }
    int ret = 0;
    for (const string &word : targetWords) {
      int num = 0;
      for (char c : word) {
        num |= (1 << (c - 'a'));
      }
      for (char c : word) {
        if (us.count(num ^ (1 << (c - 'a'))) != 0) {
          ret++;
          break;
        }
      }
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<vector<string>, vector<string>>> testCases{
      {{"ant", "act", "tack"}, {"tack", "act", "acti"}},
      {{"ab", "a"}, {"abc", "abcd"}},
  };
  for (auto &[s, t] : testCases) {
    cout << Solution().wordCount(s, t) << endl;
  }
  return 0;
}
