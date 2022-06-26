#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int minSwaps(string s) {
    int zero01{0}, zero10{0}, one01{0}, one10{0};

    for (int i = 0; i < s.size(); i++) {
      if (i % 2 == 0) {
        if (s[i] == '1') {
          zero01++;
        } else {
          one10++;
        }
      } else {
        if (s[i] == '1') {
          zero10++;
        } else {
          one01++;
        }
      }
    }

    if (zero01 != one01 && zero10 != one10) {
      return -1;
    }

    if (zero01 != one01) {
      return zero10;
    }

    if (zero10 != one10) {
      return zero01;
    }

    return std::min(zero01, zero10);
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

    int ret = Solution().minSwaps(s);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
