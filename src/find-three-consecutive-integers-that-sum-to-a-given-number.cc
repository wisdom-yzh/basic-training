#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  vector<long long> sumOfThree(long long num) {
    if (num % 3 == 0) {
      long long x = num / 3;
      return vector<long long>{x - 1, x, x + 1};
    }
    return vector<long long>{};
  }
};

int main(int argc, char *argv[]) {
  vector<long long> testCases{33, 4};
  for (auto &num : testCases) {
    for (auto &x : Solution().sumOfThree(num)) {
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}
