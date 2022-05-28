#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int longestBeautifulSubstring(string word) {
    char stateCh{0};
    int stateCount{0}, res{0};

    for (auto &ch : word) {
      switch (ch) {
      case 'a':
        if (stateCh == 'a') {
          stateCount++;
        } else {
          stateCh = 'a';
          stateCount = 1;
        }
        break;
      case 'e':
        if (stateCh == 'a' || stateCh == 'e') {
          stateCh = 'e';
          stateCount++;
        } else {
          stateCh = stateCount = 0;
        }
        break;
      case 'i':
        if (stateCh == 'e' || stateCh == 'i') {
          stateCh = 'i';
          stateCount++;
        } else {
          stateCh = stateCount = 0;
        }
        break;
      case 'o':
        if (stateCh == 'i' || stateCh == 'o') {
          stateCh = 'o';
          stateCount++;
        } else {
          stateCh = stateCount = 0;
        }
        break;
      case 'u':
        if (stateCh == 'o' || stateCh == 'u') {
          stateCh = 'u';
          stateCount++;
        } else {
          stateCh = stateCount = 0;
        }
        res = std::max(res, stateCount);
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
    string word = stringToString(line);

    int ret = Solution().longestBeautifulSubstring(word);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
