#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool winnerOfGame(string colors) {
    int sum{0};
    for (int i = 1; i < colors.size() - 1; i++) {
      if (colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A') {
        sum++;
      } else if (colors[i - 1] == 'B' && colors[i] == 'B' &&
                 colors[i + 1] == 'B') {
        sum--;
      }
    }
    return sum > 0;
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
    string colors = stringToString(line);

    bool ret = Solution().winnerOfGame(colors);

    string out = boolToString(ret);
    cout << out << endl;
  }
  return 0;
}
