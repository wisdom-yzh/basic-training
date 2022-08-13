#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
  int numberOfRounds(string loginTime, string logoutTime) {
    int a1 = stoi(loginTime.substr(0, 2)), a2 = stoi(loginTime.substr(3));
    int b1 = stoi(logoutTime.substr(0, 2)), b2 = stoi(logoutTime.substr(3));
    if (loginTime >= logoutTime) {
      b1 += 24;
    }
    int t = (b1 - a1 - 1) * 4 + (60 - a2) / 15 + b2 / 15;
    return t > 0 ? t : 0;
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
    string loginTime = stringToString(line);
    getline(cin, line);
    string logoutTime = stringToString(line);

    int ret = Solution().numberOfRounds(loginTime, logoutTime);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
