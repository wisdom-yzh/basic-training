#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int rearrangeCharacters(string s, string target) {
    std::map<char, int> sDict, tDict;
    for (auto &ch : target) {
      tDict[ch]++;
    }
    for (auto &ch : s) {
      sDict[ch]++;
    }

    int res = std::numeric_limits<int>::max();
    for (auto &[k, v] : tDict) {
      if (sDict[k] == 0 || sDict[k] < v) {
        return 0;
      }
      res = std::min(res, sDict[k] / v);
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<string, string>> testCases{{"ilovecodingonleetcode", "code"},
                                         {"abcba", "abc"},
                                         {"abbaccaddaeea", "aaaaa"}};
  for (auto &[s, t] : testCases) {
    cout << Solution().rearrangeCharacters(s, t) << endl;
  }
  return 0;
}
