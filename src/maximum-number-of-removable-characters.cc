#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
  bool checkRemoval(string &s, string &p, vector<int> &removable, int k) {
    vector<int> state(s.size(), 1);
    for (int i = 0; i < k; i++) {
      state[removable[i]] = 0;
    }
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
      if (state[i] && s[i] == p[j]) {
        j++;
        if (j == p.size()) {
          return true;
        }
      }
    }
    return false;
  }

  int maximumRemovals(string s, string p, vector<int> &removable) {
    int l = 0, r = removable.size() + 1;
    while (l < r) {
      uint32_t mid = (l + r) / 2;
      if (this->checkRemoval(s, p, removable, mid)) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l - 1;
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

void trimLeftTrailingSpaces(string &input) {
  input.erase(input.begin(), find_if(input.begin(), input.end(),
                                     [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input) {
  input.erase(
      find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); })
          .base(),
      input.end());
}

vector<int> stringToIntegerVector(string input) {
  vector<int> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  stringstream ss;
  ss.str(input);
  string item;
  char delim = ',';
  while (getline(ss, item, delim)) {
    output.push_back(stoi(item));
  }
  return output;
}

int main() {
  string line;
  while (getline(cin, line)) {
    string s = stringToString(line);
    getline(cin, line);
    string p = stringToString(line);
    getline(cin, line);
    vector<int> removable = stringToIntegerVector(line);

    int ret = Solution().maximumRemovals(s, p, removable);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
