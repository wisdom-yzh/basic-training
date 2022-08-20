#include <bitset>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  long long wonderfulSubstrings(string word) {
    long long res = 0;
    unordered_map<uint16_t, int> freq{{0, 1}};

    uint16_t sum = 0;
    for (const auto &ch : word) {
      sum ^= 1 << (ch - 'a');
      res += freq[sum];

      for (int i = 0; i < 10; i++) {
        uint16_t preSum = sum ^ (1 << i);
        res += freq[preSum];
      }

      freq[sum]++;
    }

    return res;
  }
};

int main() {
  auto testCases{vector<string>{"aba", "aabb", "he", "fiabhedce"}};
  for (auto &testCase : testCases) {
    cout << Solution().wonderfulSubstrings(testCase) << endl;
  }
  return 0;
}
