#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long numberOfWeeks(vector<int> &milestones) {
    long long sum{0};
    int maxValue{0};

    for (auto &m : milestones) {
      sum += m;
      maxValue = std::max(maxValue, m);
    }

    sum -= maxValue;
    if (sum >= maxValue) {
      return sum + maxValue;
    }

    return sum * 2 + 1;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> testCases{
      {1, 2, 3},
      {5, 2, 1},
  };
  for (auto &testCase : testCases) {
    cout << Solution().numberOfWeeks(testCase) << endl;
  }
  return 0;
}
