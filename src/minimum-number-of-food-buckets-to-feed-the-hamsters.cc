#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumBuckets(string hamsters) {
    int n = hamsters.size();
    if (n == 1 && hamsters[0] == 'H') {
      return -1;
    }
    if (hamsters[0] == 'H' && hamsters[1] == 'H' ||
        hamsters[n - 1] == 'H' && hamsters[n - 2] == 'H') {
      return -1;
    }
    for (int i = 1; i < n - 1; i++) {
      if (hamsters[i - 1] == 'H' && hamsters[i] == 'H' &&
          hamsters[i + 1] == 'H') {
        return -1;
      }
    }

    int res = 0;
    for (int i = 0; i < hamsters.size(); i++) {
      if (hamsters[i] == 'H') {
        res++;
        if (hamsters[i + 1] == '.' && hamsters[i + 2] == 'H') {
          i += 2;
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
    string hamsters = stringToString(line);

    int ret = Solution().minimumBuckets(hamsters);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
