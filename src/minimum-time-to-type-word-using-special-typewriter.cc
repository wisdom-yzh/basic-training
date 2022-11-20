#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int minTimeToType(string word) {
    int res = word.size();
    int p = 0;
    for (auto &ch : word) {
      int q = static_cast<int>(ch - 'a');
      int x = std::abs(q - p);
      int y = 26 - x;
      res += std::min(x, y);
      p = q;
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

    int ret = Solution().minTimeToType(word);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
