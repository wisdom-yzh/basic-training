#include <cassert>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

class Solution {
public:
  string maxValue(string n, int x) {
    if (n[0] == '-') {
      for (auto iter = next(n.begin());; iter++) {
        if (iter == n.end() || *iter - '0' > x) {
          n.insert(iter, x + '0');
          break;
        }
      }
    } else {
      for (auto iter = n.begin();; iter++) {
        if (iter == n.end() || *iter - '0' < x) {
          n.insert(iter, x + '0');
          break;
        }
      }
    }

    return n;
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
    string n = stringToString(line);
    getline(cin, line);
    int x = stringToInteger(line);

    string ret = Solution().maxValue(n, x);

    string out = (ret);
    cout << out << endl;
  }
  return 0;
}
