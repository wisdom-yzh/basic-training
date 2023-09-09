#include <bits/stdc++.h>
#include <set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
    set<int> ns1, ns2;
    for (auto &n : nums1) {
      ns1.insert(n);
    }
    for (auto &n : nums2) {
      ns2.insert(n);
    }
    vector<int> d1, d2;
    for (auto &x : ns1) {
      if (ns2.find(x) == ns2.end()) {
        d1.push_back(x);
      }
    }
    for (auto &x : ns2) {
      if (ns1.find(x) == ns1.end()) {
        d2.push_back(x);
      }
    }
    return {d1, d2};
  }
};

int main(int argc, char *argv[]) {
  vector<pair<vector<int>, vector<int>>> testCases{
      {{1, 2, 3}, {2, 4, 6}}, {{1, 2, 3, 3}, {1, 1, 2, 2}}};

  for (auto &[n1, n2] : testCases) {
    for (auto &row : Solution().findDifference(n1, n2)) {
      for (auto &x : row) {
        cout << x << ' ';
      }
      cout << endl;
    }
  }

  return 0;
}
