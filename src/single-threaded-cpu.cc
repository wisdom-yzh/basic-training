#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getOrder(vector<vector<int>> &tasks) {
    auto cmp{[](auto &a, auto &b) {
      return std::get<0>(a) == std::get<0>(b) ? std::get<1>(a) > std::get<1>(b)
                                              : std::get<0>(a) > std::get<0>(b);
    }};
    auto taskQ{
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       decltype(cmp)>(cmp)};
    for (int i = 0; i < tasks.size(); i++) {
      taskQ.emplace(tasks[i][0], tasks[i][1], i);
    }

    auto pendingQ{
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, decltype(cmp)>(
            cmp)};

    auto res{vector<int>(0)};
    uint32_t tick{0};

    while (res.size() < tasks.size()) {
      if (!pendingQ.empty()) {
        const auto &[duration, idx] = pendingQ.top();
        tick += duration;
        res.push_back(idx);
        pendingQ.pop();
      } else {
        const auto &[time, duration, idx] = taskQ.top();
        tick = time;
      }

      while (!taskQ.empty()) {
        const auto &[time, duration, idx] = taskQ.top();
        if (time > tick) {
          break;
        }
        pendingQ.emplace(duration, idx);
        taskQ.pop();
      }
    }

    return res;
  }
};

int main() {
  auto testCases{
      vector<vector<vector<int>>>{{{1, 2}, {2, 4}, {3, 2}, {4, 1}},
                                  {{7, 10}, {7, 12}, {7, 5}, {7, 4}, {7, 2}},
                                  {{19, 13},
                                   {16, 9},
                                   {21, 10},
                                   {32, 25},
                                   {37, 4},
                                   {49, 24},
                                   {2, 15},
                                   {38, 41},
                                   {37, 34},
                                   {33, 6},
                                   {45, 4},
                                   {18, 18},
                                   {46, 39},
                                   {12, 24}}}};
  for (auto &testCase : testCases) {
    for (const auto &x : Solution().getOrder(testCase)) {
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}
