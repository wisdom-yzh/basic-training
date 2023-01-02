#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  string reversePrefix(string word, char ch) {
    int pos = word.find(ch);
    if (pos == string::npos) {
      return word;
    }
    std::reverse(word.begin(), next(word.begin(), pos + 1));
    return word;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<string, char>> testCases{
      {"abcdefd", 'd'},
      {"xyxzxe", 'z'},
      {"abcd", 'z'},
  };
  for (auto &[w, ch] : testCases) {
    cout << Solution().reversePrefix(w, ch) << endl;
  }
  return 0;
}
