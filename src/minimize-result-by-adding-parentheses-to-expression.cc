#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string minimizeResult(string expression) {
    string first, second;
    for (size_t i = 0; i < expression.size(); i++) {
      if (expression[i] == '+') {
        first = expression.substr(0, i);
        second = expression.substr(i + 1);
      }
    }

    int minVal = std::numeric_limits<int>::max();
    string res;

    for (size_t i = 0; i < first.size(); i++) {
      for (size_t j = 1; j <= second.size(); j++) {
        string a = first.substr(0, i);
        string b = first.substr(i);
        string c = second.substr(0, j);
        string d = second.substr(j);

        int val = (a.empty() ? 1 : std::stoi(a)) *
                  (std::stoi(b) + std::stoi(c)) *
                  (d.empty() ? 1 : std::stoi(d));
        if (val < minVal) {
          minVal = val;
          res = a + "(" + b + "+" + c + ")" + d;
        }
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<string> testCases{"247+38", "12+34", "999+999"};
  for (auto &expression : testCases) {
    cout << Solution().minimizeResult(expression) << endl;
  }
  return 0;
}
