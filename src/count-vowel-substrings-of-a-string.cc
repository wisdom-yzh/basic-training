#include <cassert>
#include <iostream>
#include <set>
#include <string>
using namespace std;

class Solution {
public:
  int countVowelSubstrings(string word) {
    int res{0};
    std::set<char> s{'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < word.size(); i++) {
      std::set<char> s0{word[i]};
      for (int j = i + 1; j < word.size(); j++) {
        s0.emplace(word[j]);
        if (s == s0) {
          res++;
        }
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

    int ret = Solution().countVowelSubstrings(word);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
