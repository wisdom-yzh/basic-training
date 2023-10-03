#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> removeAnagrams(vector<string> &words) {
    vector<string> res{words[0]};

    for (int i = 0; i < words.size() - 1; i++) {
      auto word = words[i];
      std::sort(word.begin(), word.end());

      while (i + 1 < words.size()) {
        auto wordAfter = words[i + 1];
        std::sort(wordAfter.begin(), wordAfter.end());

        if (word != wordAfter) {
          res.push_back(words[i + 1]);
          break;
        }

        words.erase(next(words.begin(), i + 1));
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<string>> testCases{{"abba", "baba", "bbaa", "cd", "cd"},
                                   {"a", "b", "c", "d", "e"}};
  for (auto &words : testCases) {
    for (auto &x : Solution().removeAnagrams(words)) {
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}
