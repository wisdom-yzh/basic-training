#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int mostWordsFound(vector<string> &sentences) {
    int res{0};
    for (auto &sentence : sentences) {
      res = std::max(res, getWords(sentence));
    }
    return res;
  }

  int getWords(const string &sentence) {
    int res{0};
    string word;
    istringstream ss(sentence);
    while (getline(ss, word, ' ')) {
      res++;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<string>> testCases{
      {"alice and bob love leetcode", "i think so too",
       "this is great thanks very much"},
      {"please wait", "continue to fight", "continue to win"}};
  for (auto &testCase : testCases) {
    cout << Solution().mostWordsFound(testCase) << endl;
  }
  return 0;
}
