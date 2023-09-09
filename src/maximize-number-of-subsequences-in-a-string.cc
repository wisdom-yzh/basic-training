#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  long long maximumSubsequenceCount(string text, string pattern) {
    long long resFirst = 0;

    int count = 1;
    for (int i = 0; i < text.size(); i++) {
      if (text[i] == pattern[1]) {
        resFirst += count;
      }
      if (text[i] == pattern[0]) {
        count++;
      }
    }

    long long resLast = 0;

    count = 1;
    for (int i = text.size() - 1; i >= 0; i--) {
      if (text[i] == pattern[0]) {
        resLast += count;
      }
      if (text[i] == pattern[1]) {
        count++;
      }
    }

    return std::max(resFirst, resLast);
  }
};

int main(int argc, char *argv[]) {
  vector<pair<string, string>> testCases{{"abdcdbc", "ac"}, {"aabb", "ab"}};
  for (auto &[t, p] : testCases) {
    cout << Solution().maximumSubsequenceCount(t, p) << endl;
  }
  return 0;
}
