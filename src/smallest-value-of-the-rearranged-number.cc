#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <vector>
using namespace std;

class Solution {
public:
  long long smallestNumber(long long num) {
    if (num == 0) {
      return 0;
    }
    if (num < 0) {
      return -biggestNumber(-num);
    }

    vector<int> digits;
    while (num != 0) {
      digits.push_back(num % 10);
      num /= 10;
    }

    std::sort(digits.begin(), digits.end());
    int i = 0;
    for (; i < digits.size() && digits[i] == 0; i++)
      ;
    long long res = 0;
    res = digits[i];
    for (int j = 0; j < i; j++) {
      res = 10 * res + digits[j];
    }
    for (int j = i + 1; j < digits.size(); j++) {
      res = 10 * res + digits[j];
    }
    return res;
  }

  long long biggestNumber(long long num) {
    vector<int> digits;
    while (num != 0) {
      digits.push_back(num % 10);
      num /= 10;
    }
    std::sort(digits.begin(), digits.end(), std::greater<int>());
    long long res = 0;
    for (auto &d : digits) {
      res = 10 * res + d;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<long long> testCases{310, -7605};
  for (auto &num : testCases) {
    cout << Solution().smallestNumber(num) << endl;
  }
  return 0;
}
