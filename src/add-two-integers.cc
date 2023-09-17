#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int sum(int num1, int num2) { return num1 + num2; }
};

int main(int argc, char *argv[]) {
  vector<pair<int, int>> testCases{{1, 2}, {3, 4}};
  for (auto &[n1, n2] : testCases) {
    cout << Solution().sum(n1, n2) << endl;
  }
  return 0;
}
