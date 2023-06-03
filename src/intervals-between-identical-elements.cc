#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<long long> getDistances(vector<int> &arr) {
    vector<long long> res(arr.size(), 0);
    unordered_map<int, int> count;
    unordered_map<int, long long> sum;

    for (int i = 0; i < arr.size(); i++) {
      auto iter = count.find(arr[i]);
      if (iter != count.end()) {
        res[i] += static_cast<long long>(i) * iter->second - sum[arr[i]];
      }
      count[arr[i]]++;
      sum[arr[i]] += i;
    }

    count.clear();
    sum.clear();
    for (int i = arr.size() - 1; i >= 0; i--) {
      auto iter = count.find(arr[i]);
      if (iter != count.end()) {
        res[i] += sum[arr[i]] - static_cast<long long>(i) * iter->second;
      }
      count[arr[i]]++;
      sum[arr[i]] += i;
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> testCases{
      {2, 1, 3, 1, 2, 3, 3},
      {10, 5, 10, 10},
  };
  for (auto &testCase : testCases) {
    for (auto &x : Solution().getDistances(testCase)) {
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}
