#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Solution {
public:
  int divisorSubstrings(int num, int k) {
    int res = 0;
    auto numStr = std::to_string(num);

    for (size_t i = 0; i < numStr.size() - k + 1; i++) {
      auto subNum = std::stoi(numStr.substr(i, k));
      if (subNum != 0 && num % subNum == 0) {
        res++;
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::pair<int, int>> testCases{{430043, 2}, {240, 2}};
  for (auto &[num, k] : testCases) {
    std::cout << Solution().divisorSubstrings(num, k) << std::endl;
  }
  return 0;
}
