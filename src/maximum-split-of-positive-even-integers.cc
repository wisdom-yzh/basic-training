#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<long long> maximumEvenSplit(long long finalSum) {
    if (finalSum % 2 != 0) {
      return vector<long long>{};
    }
    vector<long long> res;

    for (int i = 2;; i += 2) {
      if (finalSum - i > i) {
        finalSum -= i;
        res.push_back(i);
        continue;
      }
      break;
    }
    res.push_back(finalSum);
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<long long> testCases{12, 7, 28};
  for (auto &finalSum : testCases) {
    for (auto x : Solution().maximumEvenSplit(finalSum)) {
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}
