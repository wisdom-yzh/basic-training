#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> divideString(string s, int k, char fill) {
    vector<string> res;
    auto p = s.begin();

    while (true) {
      string x;

      for (int i = 0; i < k; i++) {
        if (p == s.end()) {
          x.push_back(fill);
        } else {
          x.push_back(*p);
          p = next(p);
        }
      }
      res.push_back(x);

      if (p == s.end()) {
        break;
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<tuple<string, int, char>> testCases{
      {"abcdefghi", 3, 'x'},
      {"abcdefghij", 3, 'x'},
  };
  for (auto &[s, k, fill] : testCases) {
    for (auto &str : Solution().divideString(s, k, fill)) {
      cout << str << ' ';
    }
    cout << endl;
  }
  return 0;
}
