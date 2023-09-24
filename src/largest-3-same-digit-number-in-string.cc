#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string largestGoodInteger(string num) {
    char val = 0;
    for (int i = 0; i < num.size() - 2; i++) {
      if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
        val = std::max(val, num[i]);
      }
    }
    if (val == 0) {
      return "";
    }
    return std::string(3, val);
  }
};

int main(int argc, char *argv[]) {
  vector<string> testCases{"6777133339", "2300019", "42352338"};
  for (auto &num : testCases) {
    cout << Solution().largestGoodInteger(num) << endl;
  }
  return 0;
}
