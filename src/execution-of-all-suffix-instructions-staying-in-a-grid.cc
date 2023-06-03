#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> executeInstructions(int n, vector<int> &startPos, string s) {
    vector<int> res;
    for (int i = 0; i < s.size(); i++) {
      int num = 0;
      vector<int> p(startPos);

      for (int j = i; j < s.size(); j++) {
        switch (s[j]) {
        case 'R':
          p[1]++;
          break;
        case 'D':
          p[0]++;
          break;
        case 'L':
          p[1]--;
          break;
        case 'U':
          p[0]--;
          break;
        }

        if (p[0] < 0 || p[1] < 0 || p[0] == n || p[1] == n) {
          break;
        }
        num++;
      }

      res.push_back(num);
    }
    return res;
  }
};

int stringToInteger(string input) { return stoi(input); }

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

string integerVectorToString(vector<int> list, int length = -1) {
  if (length == -1) {
    length = list.size();
  }

  if (length == 0) {
    return "[]";
  }

  string result;
  for (int index = 0; index < length; index++) {
    int number = list[index];
    result += to_string(number) + ", ";
  }
  return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
  string line;
  while (getline(cin, line)) {
    int n = stringToInteger(line);
    getline(cin, line);
    vector<int> startPos = stringToIntegerVector(line);
    getline(cin, line);
    string s = stringToString(line);

    vector<int> ret = Solution().executeInstructions(n, startPos, s);

    string out = integerVectorToString(ret);
    cout << out << endl;
  }
  return 0;
}
