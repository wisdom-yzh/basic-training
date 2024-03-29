#include <cassert>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string largestOddNumber(string num) {
    for (int i = num.size() - 1; i >= 0; i--) {
      auto &ch = num[i];
      if (((ch - '0') % 2) == 1) {
        return num.substr(0, i + 1);
      }
    }

    return "";
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
    string num = stringToString(line);

    string ret = Solution().largestOddNumber(num);

    string out = (ret);
    cout << out << endl;
  }
  return 0;
}
