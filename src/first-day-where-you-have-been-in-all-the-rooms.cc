#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
  int firstDayBeenInAllRooms(vector<int> &nextVisit) {
    constexpr int MOD = 1e9 + 7;
    size_t n = nextVisit.size();
    vector<int> dp(n + 1, 0);
    for (int i = 1; i < n; i++) {
      dp[i] = (2L + 2 * dp[i - 1] - dp[nextVisit[i - 1]] + MOD) % MOD;
    }
    return dp[n - 1];
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

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> nextVisit = stringToIntegerVector(line);

    int ret = Solution().firstDayBeenInAllRooms(nextVisit);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
