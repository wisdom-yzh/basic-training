#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool areOccurrencesEqual(string s) {
    std::array<int, 26> count;
    std::fill(count.begin(), count.end(), 0);
    for (const auto &ch : s) {
      count[ch - 'a']++;
    }
    int c = 0;
    for (int i = 0; i < 26; i++) {
      if (count[i] != 0) {
        if (c == 0) {
          c = count[i];
        } else if (c != count[i]) {
          return false;
        }
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

    bool ret = Solution().areOccurrencesEqual(s);

    string out = boolToString(ret);
    cout << out << endl;
  }
  return 0;
}
