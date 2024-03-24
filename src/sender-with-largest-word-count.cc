#include <bits/stdc++.h>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
  string largestWordCount(vector<string> &messages, vector<string> &senders) {
    map<string, int> wordCount;

    for (int i = 0; i < messages.size(); i++) {
      istringstream iss(messages[i]);
      string s;
      while (getline(iss, s, ' ')) {
        wordCount[senders[i]]++;
      }
    }

    string sender;
    int res = 0;
    for (auto &[s, count] : wordCount) {
      if (count >= res) {
        res = count;
        sender = s;
      }
    }
    return sender;
  }
};

int main(int argc, char *argv[]) {
  vector<tuple<vector<string>, vector<string>>> testCases{
      {{"Hello userTwooo", "Hi userThree", "Wonderful day Alice",
        "Nice day userThree"},
       {"Alice", "userTwo", "userThree", "Alice"}},
      {{"How is leetcode for everyone", "Leetcode is useful for practice"},
       {"Bob", "Charlie"}}};
  for (auto &[messages, senders] : testCases) {
    std::cout << Solution().largestWordCount(messages, senders) << std::endl;
  }
  return 0;
}
