#include <bits/stdc++.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  string digitSum(string s, int k) {
    while (s.size() > k) {
      s = sum(s, k);
    }
    return s;
  }

  string sum(string &s, int k) {
    string res = "";
    for (int i = 0; i < s.size(); i += k) {
      int subNum = 0;
      auto subStr = i + k > s.size() ? s.substr(i) : s.substr(i, k);
      for (int j = 0; j < subStr.size(); j++) {
        subNum += static_cast<int>(subStr[j] - '0');
      }
      res += std::to_string(subNum);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<string, int>> testCases{{"11111222223", 3}, {"00000000", 3}};
  for (auto &[s, k] : testCases) {
    cout << Solution().digitSum(s, k) << endl;
  }
  return 0;
}
