#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int minSessions(vector<int> &tasks, int sessionTime) {
    int n = tasks.size();
    vector<pair<int, int>> f(1 << n, {std::numeric_limits<int>::max(),
                                      std::numeric_limits<int>::max()});
    f[0] = {1, 0};

    auto add = [&](const pair<int, int> &o, int x) -> pair<int, int> {
      if (o.second + x <= sessionTime) {
        return {o.first, o.second + x};
      }
      return {o.first + 1, x};
    };

    for (int mask = 1; mask < (1 << n); ++mask) {
      for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
          f[mask] = min(f[mask], add(f[mask ^ (1 << i)], tasks[i]));
        }
      }
    }
    return f[(1 << n) - 1].first;
  }
};

void trimLeftTrailingSpaces(string &input) {
  input.erase(input.begin(), find_if(input.begin(), input.end(),
                                     [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input) {
  input.erase(
      find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); })
          .base(),
      input.end());
}

vector<int> stringToIntegerVector(string input) {
  vector<int> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  stringstream ss;
  ss.str(input);
  string item;
  char delim = ',';
  while (getline(ss, item, delim)) {
    output.push_back(stoi(item));
  }
  return output;
}

int stringToInteger(string input) { return stoi(input); }

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> tasks = stringToIntegerVector(line);
    getline(cin, line);
    int sessionTime = stringToInteger(line);

    int ret = Solution().minSessions(tasks, sessionTime);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
