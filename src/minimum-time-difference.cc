#include <cstdlib>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <regex>
#include <vector>
using namespace std;

class Solution {
public:
  int findMinDifference(vector<string> &timePoints) {
    if (timePoints.size() > 1440) {
      return 0;
    }
    std::priority_queue<int, vector<int>, std::greater<int>> q;
    for (const auto &timePoint : timePoints) {
      q.push(formatTimeStr(timePoint));
    }

    int minDiff = std::numeric_limits<int>::max();
    int first = q.top(), prev = first, next = 0;

    while (!q.empty()) {
      prev = q.top();
      q.pop();
      if (!q.empty()) {
        next = q.top();
        minDiff = std::min(minDiff, next - prev);
        if (minDiff == 0) {
          return 0;
        }
      }
    }

    return std::min(minDiff, 24 * 60 + first - prev);
  }

  int formatTimeStr(const string &timeStr) {
    std::regex re("([\\-0-9]+)\\:([\\-0-9]+)");
    std::smatch match;
    int number = 0;

    if (std::regex_match(timeStr, match, re)) {
      if (match.size() == 3) {
        number = std::stol(match[1].str()) * 60 + std::stol(match[2].str());
      }
    }
    return number;
  }
};

int main() {
  vector<string> timePoints{"23:59", "00:00"};
  std::cout << Solution().findMinDifference(timePoints);
}
