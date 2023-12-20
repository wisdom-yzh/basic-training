#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumRounds(vector<int> &tasks) {
    map<int, int> taskMap;
    for (auto &t : tasks) {
      taskMap[t]++;
    }

    int res = 0;

    for (auto &[_, num] : taskMap) {
      int ans = -1;
      int three = num / 3;
      int remain = num % 3;

      while (three >= 0) {
        if (remain % 2 == 0) {
          int two = remain / 2;
          ans = three + two;
          break;
        }

        remain += 3;
        three--;
      }

      if (ans == -1) {
        return -1;
      }
      res += ans;
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> testCases{{2, 2, 3, 3, 2, 4, 4, 4, 4, 4}, {2, 3, 3}};
  for (auto &tasks : testCases) {
    cout << Solution().minimumRounds(tasks) << endl;
  }
  return 0;
}
