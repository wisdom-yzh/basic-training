#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

class Solution {
public:
  int firstUniqChar(string s) {
    int idx[26];
    std::fill(idx, idx + 26, std::numeric_limits<int>::max());
    for (size_t i = 0, size = s.size(); i < size; i++) {
      if (idx[s[i] - 'a'] == std::numeric_limits<int>::max()) {
        idx[s[i] - 'a'] = i;
      } else {
        idx[s[i] - 'a'] = -1;
      }
    }
    int ret = -1;
    for (auto &i : idx) {
      if (i == -1) {
        continue;
      }
      ret = (ret > i || ret == -1) && i != std::numeric_limits<int>::max()
                ? i
                : ret;
    }
    return ret;
  }
};

int main() {
  cout << Solution().firstUniqChar("leetcode") << endl;
  cout << Solution().firstUniqChar("loveleetcode") << endl;
  cout << Solution().firstUniqChar("") << endl;
  return 0;
}
