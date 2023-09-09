#include <bits/stdc++.h>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
  int digArtifacts(int n, vector<vector<int>> &artifacts,
                   vector<vector<int>> &dig) {
    vector<set<int>> aSets;
    map<int, int> coordMap;

    for (auto &coord : artifacts) {
      int x0 = coord[0], y0 = coord[1];
      int x1 = coord[2], y1 = coord[3];

      set<int> s;
      aSets.push_back(s);

      for (int x = x0; x <= x1; x++) {
        for (int y = y0; y <= y1; y++) {
          int coord = y * n + x;
          aSets.back().insert(coord);
          coordMap[coord] = aSets.size() - 1;
        }
      }
    }

    for (auto &d : dig) {
      int coord = d[0] + n * d[1];
      auto iter = coordMap.find(coord);
      if (iter != coordMap.end()) {
        aSets[iter->second].erase(coord);
      }
    }

    int res = 0;
    for (auto &s : aSets) {
      if (s.empty()) {
        res++;
      }
    }
    return res;
  }
};

int main(int argc, char **argv) {
  std::vector<std::tuple<int, vector<vector<int>>, vector<vector<int>>>>
      testCases{{2, {{0, 0, 0, 0}, {0, 1, 1, 1}}, {{0, 0}, {0, 1}}},
                {
                    2,
                    {{0, 0, 0, 0}, {0, 1, 1, 1}},
                    {{0, 0}, {0, 1}, {1, 1}},
                }};
  for (auto &[n, a, d] : testCases) {
    cout << Solution().digArtifacts(n, a, d) << endl;
  }
  return 0;
}
