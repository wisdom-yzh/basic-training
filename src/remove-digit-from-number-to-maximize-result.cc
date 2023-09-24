#include <bits/stdc++.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  string removeDigit(string number, char digit) {
    int goalIndex = 0;

    for (int i = 0; i < number.size(); i++) {
      if (number[i] == digit) {
        if (i == number.size() - 1) {
          goalIndex = i;
          continue;
        }
        auto next = number[i + 1];
        if (next > number[i]) {
          number.erase(i, 1);
          return number;
        } else {
          goalIndex = i;
        }
      }
    }

    number.erase(goalIndex, 1);
    return number;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<string, char>> testCases{
      {"123", '3'}, {"1231", '1'}, {"551", '5'}};
  for (auto &[n, d] : testCases) {
    cout << Solution().removeDigit(n, d) << endl;
  }
  return 0;
}
