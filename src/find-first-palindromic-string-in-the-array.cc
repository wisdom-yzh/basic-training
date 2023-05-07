#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  string firstPalindrome(vector<string> &words) {
    for (const auto &word : words) {
      if (isPalindrome(word)) {
        return word;
      }
    }
    return "";
  }

  bool isPalindrome(const string &word) {
    int n = word.size();
    for (int i = 0; i < n / 2; i++) {
      if (word[i] != word[n - 1 - i]) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<string>> testCases{
      {"abc", "car", "ada", "racecar", "cool"},
      {"notapalindrome", "racecar"},
      {"def", "ghi"},
  };
  for (auto &testCase : testCases) {
    cout << Solution().firstPalindrome(testCase) << endl;
  }
  return 0;
}
