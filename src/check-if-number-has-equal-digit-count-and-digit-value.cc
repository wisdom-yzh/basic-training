#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  bool digitCount(string num) {
    std::array<int, 10> count;
    std::fill(count.begin(), count.end(), 0);

    for (auto &ch : num) {
      count[ch - '0']++;
    }

    for (int i = 0; i < num.size(); i++) {
      if (num[i] - '0' != count[i]) {
        return false;
      }
    }

    return true;
  }
};

int main(int argc, char *argv[]) {
  vector<string> testCases{"1210", "030"};

  for (auto &num : testCases) {
    cout << boolalpha << Solution().digitCount(num) << endl;
  }

  return 0;
}
