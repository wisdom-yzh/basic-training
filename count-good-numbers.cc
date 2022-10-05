#include <cstdint>
#include <iostream>
#include <ostream>
#include <vector>

class Solution {
public:
  constexpr static int MOD = 1e9 + 7;

  uint64_t pow(uint64_t n, uint64_t e) {
    uint64_t res{1L};

    while (e > 0) {
      if ((e & 1) == 1) {
        res *= n;
        res %= MOD;
      }
      n *= n;
      n %= MOD;
      e >>= 1;
    }

    return res;
  }

  int countGoodNumbers(long long n) {
    auto even = (n + 1) >> 1, odd = n >> 1;

    return static_cast<int>((pow(5, even) * pow(4, odd)) % MOD);
  }
};

int main() {
  std::vector<long long> testCases{1, 4, 50};
  for (const auto &n : testCases) {
    std::cout << Solution().countGoodNumbers(n) << std::endl;
  }
  return 0;
}
