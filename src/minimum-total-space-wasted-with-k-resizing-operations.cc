#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
  int minSpaceWastedKResizing(vector<int> &nums, int k) {
    int n = nums.size();

    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      int best = std::numeric_limits<int>::min();
      int total = 0;

      for (int j = i; j < n; ++j) {
        best = max(best, nums[j]);
        total += nums[j];
        g[i][j] = best * (j - i + 1) - total;
      }
    }

    vector<vector<int>> f(
        n, vector<int>(k + 2, std::numeric_limits<int>::max() / 2));
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j <= k + 1; ++j) {
        for (int i0 = 0; i0 <= i; ++i0) {
          f[i][j] = min(f[i][j], (i0 == 0 ? 0 : f[i0 - 1][j - 1]) + g[i0][i]);
        }
      }
    }

    return f[n - 1][k + 1];
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
    vector<int> nums = stringToIntegerVector(line);
    getline(cin, line);
    int k = stringToInteger(line);

    int ret = Solution().minSpaceWastedKResizing(nums, k);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
