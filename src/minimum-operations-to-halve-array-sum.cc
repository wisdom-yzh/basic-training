#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int halveArray(vector<int> &nums) {
    double sum = 0, goal = 0;

    std::priority_queue<double> q;
    for (auto &num : nums) {
      sum += num;
      q.push(num);
    }

    int res = 0;
    goal = sum / 2.0;
    while (sum > goal) {
      auto x = q.top();
      q.pop();

      sum -= (x / 2);
      q.push(x / 2);
      res++;
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> testCases{{5, 19, 8, 1}, {3, 8, 20}, {1}};
  for (auto &testCase : testCases) {
    cout << Solution().halveArray(testCase) << endl;
  }
  return 0;
}
