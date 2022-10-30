#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int getLucky(string s, int k) {
    string str;
    for (auto &ch : s) {
      str += std::to_string(static_cast<int>(ch - 'a' + 1));
    }
    for (int i = 0; i < k; i++) {
      str = convert(str);
    }
    return std::stoi(str);
  }

  string convert(string &s) {
    int res = 0;
    for (auto &ch : s) {
      res += static_cast<int>(ch - '0');
    }
    return std::to_string(res);
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

int stringToInteger(string input) { return stoi(input); }

int main() {
  string line;
  while (getline(cin, line)) {
    string s = stringToString(line);
    getline(cin, line);
    int k = stringToInteger(line);

    int ret = Solution().getLucky(s, k);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
