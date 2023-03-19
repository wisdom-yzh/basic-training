#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <utility>
#include <vector>

class Solution {
public:
  std::string kthDistinct(std::vector<std::string> &arr, int k) {
    std::vector<bool> notDistinct(arr.size(), false);
    std::map<std::string, int> idxMap;

    for (int i = 0; i < arr.size(); i++) {
      auto iter = idxMap.find(arr[i]);
      if (iter != idxMap.end()) {
        notDistinct[iter->second] = true;
        notDistinct[i] = true;
      } else {
        idxMap.emplace(arr[i], i);
      }
    }

    int j = 0;
    for (int i = 0; i < notDistinct.size(); i++) {
      if (notDistinct[i]) {
        continue;
      }
      j++;
      if (j == k) {
        return arr[i];
      }
    }
    return "";
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::pair<std::vector<std::string>, int>> testCases{
      {{"d", "b", "c", "b", "c", "a"}, 2},
      {{"aaa", "aa", "a"}, 1},
      {{"a", "b", "a"}, 3}};
  for (auto &[arr, k] : testCases) {
    std::cout << Solution().kthDistinct(arr, k) << std::endl;
  }
  return 0;
}
