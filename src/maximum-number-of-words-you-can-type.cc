#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int canBeTypedWords(string text, string brokenLetters) {
    std::istringstream iss;
    iss.str(text);

    std::unordered_set<char> set(brokenLetters.begin(), brokenLetters.end());

    int res = 0;
    string slice;
    while (getline(iss, slice, ' ')) {
      bool found = false;

      for (auto &ch : slice) {
        if (set.find(ch) != set.end()) {
          found = true;
        }
      }

      if (!found) {
        res++;
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
    string text = stringToString(line);
    getline(cin, line);
    string brokenLetters = stringToString(line);

    int ret = Solution().canBeTypedWords(text, brokenLetters);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
