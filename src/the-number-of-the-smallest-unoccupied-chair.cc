#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int smallestChair(vector<vector<int>> &times, int targetFriend) {
    vector<pair<int, int>> arrive, leave;
    for (int i = 0; i < times.size(); i++) {
      arrive.emplace_back(times[i][0], i);
      leave.emplace_back(times[i][1], i);
    }
    std::sort(arrive.begin(), arrive.end());
    std::sort(leave.begin(), leave.end());

    std::map<int, int> peopleWithChair;
    std::priority_queue<int, vector<int>, greater<int>> freeChair;
    for (int i = 0; i < times.size(); i++) {
      freeChair.push(i);
    }

    int idx = 0;
    for (auto &&[time, person] : arrive) {
      while (idx < times.size() && leave[idx].first <= time) {
        freeChair.push(peopleWithChair[leave[idx].second]);
        idx++;
      }
      int seat = freeChair.top();
      peopleWithChair[person] = seat;
      freeChair.pop();
      if (person == targetFriend) {
        return seat;
      }
    }

    return -1;
  }
};

int main() {
  vector<pair<vector<vector<int>>, int>> testCases{
      {{{1, 4}, {2, 3}, {4, 6}}, 1},
      {{{3, 10}, {1, 5}, {2, 6}}, 0},
      {{{3, 100000},  {37, 100000}, {34, 100000}, {16, 100000}, {28, 100000},
        {19, 100000}, {14, 100000}, {29, 100000}, {5, 100000},  {9, 100000},
        {25, 100000}, {18, 100000}, {31, 100000}, {17, 100000}, {12, 100000},
        {36, 100000}, {30, 100000}, {13, 100000}, {27, 100000}, {10, 100000},
        {21, 100000}, {38, 100000}, {11, 100000}, {46, 100000}, {2, 100000},
        {33, 100000}, {20, 100000}, {8, 100000},  {35, 100000}, {43, 100000},
        {23, 100000}, {22, 100000}, {15, 100000}, {44, 100000}, {45, 100000},
        {7, 100000},  {24, 100000}, {42, 100000}, {6, 100000},  {1, 100000},
        {26, 100000}, {39, 100000}, {32, 100000}, {40, 100000}, {41, 100000},
        {4, 100000}},
       23}};
  for (auto &[times, targetFriend] : testCases) {
    cout << Solution().smallestChair(times, targetFriend) << endl;
  }
  return 0;
}
