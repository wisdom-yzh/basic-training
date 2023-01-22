#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
  int maxConsecutiveAnswers(string answerKey, int k) {
    return std::max(maxSlidingWindow(answerKey, 'T', k),
                    maxSlidingWindow(answerKey, 'F', k));
  }

  int maxSlidingWindow(string &key, char ch, int k) {
    queue<int> next;
    int res = 0, flipCount = 0, left = 0;

    for (int i = 0; i < key.size(); i++) {
      if (key[i] != ch) {
        next.push(i);
        if (flipCount == k) {
          left = next.front() + 1;
          next.pop();
        } else {
          flipCount++;
        }
      }

      res = std::max(res, i - left + 1);
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
    string answerKey = stringToString(line);
    getline(cin, line);
    int k = stringToInteger(line);

    int ret = Solution().maxConsecutiveAnswers(answerKey, k);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
