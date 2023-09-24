#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int countPrefixes(vector<string> &words, string s) {
    int res = 0;
    for (const auto &w : words) {
      if (s.substr(0, w.size()) == w) {
        res++;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<pair<vector<string>, string>> testCases{
      {{"a", "b", "c", "ab", "bc", "abc"}, "abc"},
      {{"a", "a"}, "aa"},
      {{"feh", "w", "w",    "lwd", "c", "s", "vk", "zwlv", "n", "w",  "sw",
        "qrd", "w", "w",    "mqe", "w", "w", "w",  "gb",   "w", "qy", "xs",
        "br",  "w", "rypg", "wh",  "g", "w", "w",  "fh",   "w", "w",  "sccy"},
       "w"}};
  for (auto &[w, s] : testCases) {
    cout << Solution().countPrefixes(w, s) << endl;
  }
  return 0;
}
