#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

class Solution {
public:
  int minFlips(string s) {
    auto res{std::numeric_limits<int>::max()};
    int n = s.size();
    int op{0};
    s += s;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] - '0' != i % 2) {
        op++;
      }
      if (i >= n && s[i - n] - '0' != (i - n) % 2) {
        op--;
      }
      if (i >= n - 1) {
        res = std::min(res, std::min(op, n - op));
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

    int ret = Solution().minFlips(s);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
