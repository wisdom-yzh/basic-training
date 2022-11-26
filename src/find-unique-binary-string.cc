#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string findDifferentBinaryString(vector<string> &nums) {
    vector<bool> exist((1 << nums[0].size()), true);
    for (auto num : nums) {
      exist[std::stoi(num, 0, 2)] = false;
    }
    for (int i = 0; i < exist.size(); i++) {
      if (exist[i]) {
        return std::bitset<16>(i).to_string().substr(16 - nums[0].size());
      }
    }
    return "";
  }
};

int main() {
  vector<vector<string>> testCases{
      {"01", "10"}, {"00", "01"}, {"111", "011", "001"}};

  for (auto testCase : testCases) {
    cout << Solution().findDifferentBinaryString(testCase) << endl;
  }
  return 0;
}
