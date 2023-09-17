#include <bits/stdc++.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int getTime(string &s) {
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
  }

  int convertTime(string current, string correct) {
    int diff = getTime(correct) - getTime(current);
    int ops[4] = {60, 15, 5, 1};
    int ans = 0;

    for (int op : ops) {
      ans += diff / op;
      diff %= op;
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<string, string>> testCases{{"02:30", "04:35"},
                                         {"11:00", "11:01"}};
  for (auto &[current, correct] : testCases) {
    std::cout << Solution().convertTime(current, correct) << std::endl;
  }
  return 0;
}
