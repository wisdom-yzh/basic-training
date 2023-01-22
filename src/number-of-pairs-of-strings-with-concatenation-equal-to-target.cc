#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int numOfPairs(vector<string> &nums, string target) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < nums.size(); j++) {
        if (i == j) {
          continue;
        }
        if (nums[i] + nums[j] == target) {
          res++;
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<pair<vector<string>, string>> testCases{
      {{"777", "7", "77", "77"}, "7777"},
      {{"123", "4", "12", "34"}, "1234"},
      {{"1", "1", "1"}, "11"}};
  for (auto &[nums, target] : testCases) {
    cout << Solution().numOfPairs(nums, target) << endl;
  }
  return 0;
}
