#include <iostream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  bool isPrefixString(string s, vector<string> &words) {
    string tmp;
    for (auto &w : words) {
      tmp += w;
      if (tmp == s) {
        return true;
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<string, vector<string>>> testCases{
      {"iloveleetcode", {"i", "love", "leetcode", "apples"}},
      {"iloveleetcode", {"apples", "i", "love", "leetcode"}}};
  for (auto &[s, words] : testCases) {
    cout << boolalpha << Solution().isPrefixString(s, words) << endl;
  }
  return 0;
}
