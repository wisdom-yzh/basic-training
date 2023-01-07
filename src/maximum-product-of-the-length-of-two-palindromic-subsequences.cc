#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool isPalindromic(const string &s) {
    for (int i = 0; i < s.size() / 2; i++) {
      if (s[i] != s[s.size() - 1 - i]) {
        return false;
      }
    }
    return true;
  }

  int dfs(const string &s, int pos, string a, string b) {
    if (pos == s.size()) {
      return (isPalindromic(a) && isPalindromic(b))
                 ? static_cast<int>(a.size() * b.size())
                 : 0;
    }

    int res = 0;
    res = std::max(res, dfs(s, pos + 1, a, b));
    res = std::max(res, dfs(s, pos + 1, a + s[pos], b));
    res = std::max(res, dfs(s, pos + 1, a, b + s[pos]));
    return res;
  }

  int maxProduct(string s) { return dfs(s, 0, "", ""); }
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

    int ret = Solution().maxProduct(s);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
