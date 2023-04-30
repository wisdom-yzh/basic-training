#include <cassert>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string decodeCiphertext(string encodedText, int rows) {
    string res;
    int m = rows;
    int n = encodedText.size() / rows;
    int i = 0;
    int j = 0;
    while (i < m && j < n) {
      res += encodedText[i * n + j];
      ++i;
      ++j;
      if (i == m) {
        i = 0;
        j -= (m - 1);
      }
    }
    while (res.back() == ' ') {
      res.pop_back();
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

int stringToInteger(string input) { return stoi(input); }

int main() {
  string line;
  while (getline(cin, line)) {
    string encodedText = stringToString(line);
    getline(cin, line);
    int rows = stringToInteger(line);

    string ret = Solution().decodeCiphertext(encodedText, rows);

    string out = (ret);
    cout << out << endl;
  }
  return 0;
}
