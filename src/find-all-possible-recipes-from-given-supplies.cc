#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> findAllRecipes(vector<string> &recipes,
                                vector<vector<string>> &ingredients,
                                vector<string> &supplies) {
    vector<string> res;
    queue<string> q;
    for (auto &s : supplies) {
      q.push(s);
    }

    while (!q.empty()) {
      auto &s = q.front();
      for (int i = 0; i < ingredients.size(); i++) {
        auto &item = ingredients[i];
        auto iter = std::find(item.begin(), item.end(), s);
        if (iter == item.end()) {
          continue;
        }
        item.erase(iter);
        if (item.empty()) {
          res.push_back(recipes[i]);
          q.push(recipes[i]);
        }
      }
      q.pop();
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<tuple<vector<string>, vector<vector<string>>, vector<string>>>
      testCases{
          {{"bread"}, {{"yeast", "flour"}}, {"yeast", "flour", "corn"}},
          {{"bread", "sandwich"},
           {{"yeast", "flour"}, {"bread", "meat"}},
           {"yeast", "flour", "meat"}},
          {{"bread", "sandwich", "burger"},
           {{"yeast", "flour"},
            {"bread", "meat"},
            {"sandwich", "meat", "bread"}},
           {"yeast", "flour", "meat"}},
      };
  for (auto &[r, i, s] : testCases) {
    for (auto &x : Solution().findAllRecipes(r, i, s)) {
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}
