#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include <iterator>
#include <string>
using namespace std;

class Solution {
public:
  string capitalizeTitle(string title) {
    auto iter = title.begin();
    while (true) {
      auto splitter = std::find(iter, title.end(), ' ');
      if (distance(iter, splitter) <= 2) {
        std::transform(iter, splitter, iter,
                       [](auto ch) { return tolower(ch); });
      } else {
        *iter = toupper(*iter);
        iter++;
        std::transform(iter, splitter, iter,
                       [](auto ch) { return tolower(ch); });
      }

      if (splitter == title.end()) {
        break;
      }
      iter = next(splitter);
    }
    return title;
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
    string title = stringToString(line);

    string ret = Solution().capitalizeTitle(title);

    string out = (ret);
    cout << out << endl;
  }
  return 0;
}
