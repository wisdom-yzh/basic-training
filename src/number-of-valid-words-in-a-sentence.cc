#include <algorithm>
#include <cassert>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
  int countValidWords(string sentence) {
    std::regex re("(([a-z]+-)?[a-z]+)?[!,.]?");
    std::string word;
    istringstream iss(sentence);

    int count{0};
    while (iss >> word) {
      if (std::regex_match(word, re)) {
        count++;
      }
    }

    return count;
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
    string sentence = stringToString(line);

    int ret = Solution().countValidWords(sentence);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
