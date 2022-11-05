#include <iostream>
#include <vector>

class Solution {
public:
  long long minimumPerimeter(long long neededApples) {
    long long i = 0, sum = 0;
    while (sum < neededApples) {
      i++;
      sum += 12 * i * i;
    }
    return i * 8;
  }
};

int main(int argc, char *argv[]) {
  std::vector<long long> testCases{1, 13, 1000000000};
  for (auto &testCase : testCases) {
    std::cout << Solution().minimumPerimeter(testCase) << std::endl;
  }
  return 0;
}
