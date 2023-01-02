#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution {
public:
  int numberOfWeakCharacters(vector<vector<int>> &properties) {
    std::sort(properties.begin(), properties.end(), [](auto &a, auto &b) {
      if (a[0] == b[0]) {
        return a[1] < b[1];
      }
      return a[0] > b[0];
    });

    int res = 0, maxVal = std::numeric_limits<int>::min();
    for (auto &x : properties) {
      if (maxVal > x[1]) {
        res++;
      } else {
        maxVal = x[1];
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<vector<int>>> testCases{
      {{5, 5}, {6, 3}, {3, 6}}, {{2, 2}, {3, 3}}, {{1, 5}, {10, 4}, {4, 3}}};
  for (auto &testCase : testCases) {
    cout << Solution().numberOfWeakCharacters(testCase) << endl;
  }
  return 0;
}
