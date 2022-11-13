#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int numOfStrings(vector<string> &patterns, string word) {
    int res{0};
    for (auto &p : patterns) {
      if (word.find(p) != word.npos) {
        res++;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<vector<string>, string>> testCases{
      {{"a", "abc", "bc", "d"}, "abc"},
      {{"a", "b", "c"}, "aaaaabbbbb"},
      {{"a", "a", "a"}, "ab"}};
  for (auto &[p, w] : testCases) {
    cout << Solution().numOfStrings(p, w) << endl;
  }
  return 0;
}
