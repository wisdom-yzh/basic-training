#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int longestPalindrome(vector<string> &words) {
    int dict[26][26];
    std::memset(dict, 0, sizeof(dict));

    for (const auto &word : words) {
      dict[word[0] - 'a'][word[1] - 'a']++;
    }

    int res = 0;
    bool hasSingleElement = false;
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        if (dict[i][j] == 0) {
          continue;
        }
        if (i == j) {
          if (dict[i][j] / 2 >= 1) {
            res += (dict[i][j] / 2) * 4;
          }
          if (!hasSingleElement && (dict[i][j] % 2) != 0) {
            hasSingleElement = true;
          }
          dict[i][j] = 0;
        } else {
          int x = std::min(dict[i][j], dict[j][i]);
          res += x * 2;
        }
      }
    }
    if (hasSingleElement) {
      res += 2;
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<string>> testCases{
      {"lc", "cl", "gg"},
      {"ab", "ty", "yt", "lc", "cl", "ab"},
      {"cc", "ll", "xx"},
      {"dd", "aa", "bb", "dd", "aa", "dd", "bb", "dd", "aa", "cc", "bb", "cc",
       "dd", "cc"},
  };
  for (auto &testCase : testCases) {
    cout << Solution().longestPalindrome(testCase) << endl;
  }
  return 0;
}
