#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
  int minSwaps(string s) {
    int p = 0, q = s.size() - 1, stk = 0;

    int res{0};
    while (p < q) {
      if (s[p] == '[') {
        stk++;
        p++;
      } else { /* if s[p] == ']' */
        if (stk > 0) {
          stk--;
          p++;
        } else {
          while (s[q] != '[') {
            q--;
          }
          std::swap(s[p], s[q]);
          res++;
        }
      }
    }
    return res;
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

int main() {
  string line;
  while (getline(cin, line)) {
    string s = stringToString(line);

    int ret = Solution().minSwaps(s);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
