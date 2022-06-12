#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

class Solution {
public:
  int getMinSwaps(string num, int k) {
    string resNum{num};
    for (int i = 0; i < k; i++) {
      nextPermutation(resNum);
    }

    int result{0};
    for (int i = 0; i < num.size(); i++) {
      if (num[i] != resNum[i]) {
        for (int j = i + 1; j < num.size(); j++) {
          if (num[j] == resNum[i]) {
            for (int k = j - 1; k >= i; k--) {
              result++;
              std::swap(num[k], num[k + 1]);
            }
            break;
          }
        }
      }
    }

    return result;
  }

  void nextPermutation(string &nums) {
    auto p = nums.end();
    for (auto i = nums.begin() + 1; i != nums.end(); i++) {
      if (*i > *(i - 1)) {
        p = i - 1;
      }
    }

    if (p == nums.end()) {
      std::sort(nums.begin(), nums.end());
      return;
    }

    auto replacedIterator = p + 1;
    for (auto i = replacedIterator + 1; i != nums.end(); i++) {
      if (*i > *p && *i < *replacedIterator) {
        replacedIterator = i;
      }
    }
    std::swap(*replacedIterator, *p);
    std::sort(p + 1, nums.end());
  }
};

string stringToString(string input) {
  assert(input.length() >= 2);
  string result;
  for (int i = 1; i < input.length() - 1; i++) {
    char currentChar = input[i];
    if (input[i] == '\\') {
      char nextChar = input[i + 1];
      switch (nextChar) {
      case '\"':
        result.push_back('\"');
        break;
      case '/':
        result.push_back('/');
        break;
      case '\\':
        result.push_back('\\');
        break;
      case 'b':
        result.push_back('\b');
        break;
      case 'f':
        result.push_back('\f');
        break;
      case 'r':
        result.push_back('\r');
        break;
      case 'n':
        result.push_back('\n');
        break;
      case 't':
        result.push_back('\t');
        break;
      default:
        break;
      }
      i++;
    } else {
      result.push_back(currentChar);
    }
  }
  return result;
}

int stringToInteger(string input) { return stoi(input); }

int main() {
  string line;
  while (getline(cin, line)) {
    string num = stringToString(line);
    getline(cin, line);
    int k = stringToInteger(line);

    int ret = Solution().getMinSwaps(num, k);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
