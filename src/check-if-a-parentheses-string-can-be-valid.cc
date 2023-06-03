#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canBeValid(string s, string locked) {
    int n = s.size();
    if (n % 2 != 0) {
      return false;
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      if (locked[i] == '1' && s[i] == ')') {
        if (--sum < 0) {
          return false;
        }
      } else {
        ++sum;
      }
    }
    sum = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (locked[i] == '1' && s[i] == '(') {
        if (--sum < 0) {
          return false;
        }
      } else {
        ++sum;
      }
    }
    return true;
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

string boolToString(bool input) { return input ? "True" : "False"; }

int main() {
  string line;
  while (getline(cin, line)) {
    string s = stringToString(line);
    getline(cin, line);
    string locked = stringToString(line);

    bool ret = Solution().canBeValid(s, locked);

    string out = boolToString(ret);
    cout << out << endl;
  }
  return 0;
}
