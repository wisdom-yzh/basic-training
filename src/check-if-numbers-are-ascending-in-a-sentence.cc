#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
  bool areNumbersAscending(string s) {
    int prev = 0, num = 0;
    istringstream ss(s);
    std::string line;
    while (getline(ss, line, ' ')) {
      if (line[0] >= '0' && line[0] <= '9') {
        num = std::stoi(line);
        if (num <= prev) {
          return false;
        }
        prev = num;
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

    bool ret = Solution().areNumbersAscending(s);

    string out = boolToString(ret);
    cout << out << endl;
  }
  return 0;
}
