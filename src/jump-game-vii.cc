#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool canReach(string s, int minJump, int maxJump) {
    vector<int> f(s.size(), 0);
    vector<int64_t> pre(s.size(), 0);

    f[0] = 1;
    for (int i = 0; i < minJump; i++) {
      pre[i] = 1;
    }

    for (int i = minJump; i < s.size(); i++) {
      auto left{i - maxJump}, right{i - minJump};
      if (s[i] == '0') {
        f[i] = (pre[right] - (left <= 0 ? 0 : pre[left - 1])) != 0 ? 1 : 0;
      }
      pre[i] = pre[i - 1] + f[i];
    }

    return f[s.size() - 1];
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

string boolToString(bool input) { return input ? "True" : "False"; }

int main() {
  string line;
  while (getline(cin, line)) {
    string s = stringToString(line);
    getline(cin, line);
    int minJump = stringToInteger(line);
    getline(cin, line);
    int maxJump = stringToInteger(line);

    bool ret = Solution().canReach(s, minJump, maxJump);

    string out = boolToString(ret);
    cout << out << endl;
  }
  return 0;
}
