#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

class Solution {
public:
  struct Event {
    int ts;
    int op;
    int val;

    Event(int _ts, int _op, int _val) : ts(_ts), op(_op), val(_val) {}
    bool operator<(const Event &that) const {
      return std::tie(ts, op) < std::tie(that.ts, that.op);
    }
  };

  int maxTwoEvents(std::vector<std::vector<int>> &events) {
    std::vector<Event> evs;
    for (const auto &event : events) {
      evs.emplace_back(event[0], 0, event[2]);
      evs.emplace_back(event[1], 1, event[2]);
    }
    std::sort(evs.begin(), evs.end());

    int ans = 0, bestFirst = 0;
    for (const auto &[ts, op, val] : evs) {
      if (op == 0) {
        ans = std::max(ans, val + bestFirst);
      } else {
        bestFirst = std::max(bestFirst, val);
      }
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<std::vector<int>>> testCases{
      {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}},
      {{1, 3, 2}, {4, 5, 2}, {1, 5, 5}},
      {{1, 5, 3}, {1, 5, 1}, {6, 6, 5}}};
  for (auto &events : testCases) {
    std::cout << Solution().maxTwoEvents(events) << std::endl;
  }
  return 0;
}
