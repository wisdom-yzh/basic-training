#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
  string maximumNumber(string num, vector<int> &change) {
    string res = num;
    bool found = false;

    for (int i = 0; i < num.size(); i++) {
      if (change[num[i] - '0'] > (num[i] - '0')) {
        found = true;
        res[i] = change[num[i] - '0'] + '0';
        for (int j = i + 1; j < num.size(); j++) {
          if (change[num[j] - '0'] < num[j] - '0') {
            break;
          }
          res[j] = change[num[j] - '0'] + '0';
        }
      }

      if (found) {
        break;
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
    string num = stringToString(line);
    getline(cin, line);
    vector<int> change = stringToIntegerVector(line);

    string ret = Solution().maximumNumber(num, change);

    string out = (ret);
    cout << out << endl;
  }
  return 0;
}
