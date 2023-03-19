#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumOperations(vector<int> &nums, int start, int goal) {
    std::map<int, int> table;
    std::queue<std::pair<int, int>> q;
    q.push({start, 0});

    while (!q.empty()) {
      auto [current, op] = q.front();
      if (current == goal) {
        return op;
      }

      if (table.find(current) != table.end() || current < 0 || current > 1000) {
        q.pop();
        continue;
      }

      table.emplace(current, op + 1);

      for (auto &num : nums) {
        q.emplace(current + num, op + 1);
        q.emplace(current - num, op + 1);
        q.emplace(current ^ num, op + 1);
      }

      q.pop();
    }

    return -1;
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
    int start = stringToInteger(line);
    getline(cin, line);
    int goal = stringToInteger(line);

    int ret = Solution().minimumOperations(nums, start, goal);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
