#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  long long countVowels(string word) {
    long long ans = 0, n = word.size();
    for (int i = 0; i < n; ++i) {
      if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
          word[i] == 'o' || word[i] == 'u') {
        ans += (i + 1) * (n - i);
      }
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  vector<string> testCases{
      "aba",
      "abc",
      "ltcd",
      "noosabasboosa",
  };
  for (auto &testCase : testCases) {
    cout << Solution().countVowels(testCase) << endl;
  }
  return 0;
}
