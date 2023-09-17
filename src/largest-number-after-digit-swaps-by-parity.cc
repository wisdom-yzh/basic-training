#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int largestInteger(int num) {
    priority_queue<int, vector<int>, std::greater<>> p, q;

    int val = num;
    vector<int> even;
    while (val > 0) {
      auto x = val % 10;
      if (x % 2 == 0) {
        even.push_back(true);
        p.push(x);
      } else {
        even.push_back(false);
        q.push(x);
      }
      val /= 10;
    }

    int res = 0;
    for (int i = 0; i < even.size(); i++) {
      if (even[i]) {
        res += p.top() * std::pow(10, i);
        p.pop();
      } else {
        res += q.top() * std::pow(10, i);
        q.pop();
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<int> testCases{1234, 65875};
  for (auto &num : testCases) {
    cout << Solution().largestInteger(num) << endl;
  }
  return 0;
}
