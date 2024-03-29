#include <cassert>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool splitString(string s) {
    for (int i = s.size() - 2; i >= 0; i--) {
      auto firstNum{std::stoul(s.substr(0, i + 1))};
      if (recursiveSplitString(s, i + 1, firstNum)) {
        return true;
      }
    }
    return false;
  }

  bool recursiveSplitString(string &s, int pos, uint64_t number) {
    if (pos == s.size()) {
      return true;
    }

    bool result = false;
    uint64_t currentNum{0};
    for (int i = pos; i < s.size() && currentNum < number && !result; i++) {
      currentNum = currentNum * 10 + (s[i] - '0');
      if (currentNum == number - 1) {
        result |= recursiveSplitString(s, i + 1, currentNum);
      }
    }
    return result;
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

    bool ret = Solution().splitString(s);

    string out = boolToString(ret);
    cout << out << endl;
  }
  return 0;
}
