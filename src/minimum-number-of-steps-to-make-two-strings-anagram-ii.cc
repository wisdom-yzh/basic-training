#include <bits/stdc++.h>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int minSteps(string s, string t) {
    auto ms = convert(s);
    auto mt = convert(t);

    return diff(ms, mt) + diff(mt, ms);
  }

  map<char, int> convert(string &s) {
    map<char, int> m;
    for (auto &ch : s) {
      m[ch]++;
    }
    return m;
  }

  int diff(const map<char, int> &s, const map<char, int> &t) {
    int count = 0;

    for (auto &[ch, val] : s) {
      auto iter = t.find(ch);
      if (iter == t.end()) {
        count += val;
      } else {
        count += std::max(0, val - iter->second);
      }
    }

    return count;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<string, string>> testCases{
      {"leetcode", "coats"},
      {"night", "thing"},
  };
  for (auto [s, t] : testCases) {
    cout << Solution().minSteps(s, t) << endl;
  }
  return 0;
}
