#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>
using namespace std;

class Solution {
public:
  int countPalindromicSubsequence(string s) {
    int res = 0;

    for (char i = 'a'; i <= 'z'; i++) {
      auto [l, r] = find(s, i);
      if (l == -1 || r - l <= 1) {
        continue;
      }

      std::unordered_set<char> set;
      for (int j = l + 1; j < r; j++) {
        set.insert(s[j]);
      }
      res += set.size();
    }

    return res;
  }

  std::pair<int, int> find(string &s, char ch) {
    std::pair<int, int> res{-1, -1};

    for (int i = 0; i < s.size(); i++) {
      if (ch == s[i]) {
        res.first = i;
        break;
      }
    }

    if (res.first == -1) {
      return res;
    }

    for (int i = s.size() - 1; i >= 0; i--) {
      if (ch == s[i]) {
        res.second = i;
        break;
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

    int ret = Solution().countPalindromicSubsequence(s);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
