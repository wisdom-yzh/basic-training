#include <array>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
  bool checkAlmostEquivalent(string word1, string word2) {
    std::array<int, 26> freq;
    std::fill(freq.begin(), freq.end(), 0);

    for (auto &ch : word1) {
      freq[ch - 'a']++;
    }
    for (auto &ch : word2) {
      freq[ch - 'a']--;
    }
    for (auto &diff : freq) {
      if (diff > 3 || diff < -3) {
        return false;
      }
    }
    return true;
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
    string word1 = stringToString(line);
    getline(cin, line);
    string word2 = stringToString(line);

    bool ret = Solution().checkAlmostEquivalent(word1, word2);

    string out = boolToString(ret);
    cout << out << endl;
  }
  return 0;
}
