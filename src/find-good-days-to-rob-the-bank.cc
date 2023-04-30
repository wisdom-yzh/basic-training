#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> goodDaysToRobBank(vector<int> &security, int time) {
    if (security.size() < time * 2 + 1) {
      return {};
    }
    vector<int> left(security.size(), 0), right(security.size(), 0);
    for (int i = 1; i < security.size(); i++) {
      if (security[i] <= security[i - 1]) {
        left[i] = left[i - 1] + 1;
      }
    }
    for (int i = security.size() - 2; i >= 0; i--) {
      if (security[i + 1] >= security[i]) {
        right[i] = right[i + 1] + 1;
      }
    }
    vector<int> res;
    for (int i = time; i < security.size() - time; i++) {
      if (left[i] >= time && right[i] >= time) {
        res.push_back(i);
      }
    }
    return res;
  }
};

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

int stringToInteger(string input) { return stoi(input); }

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
    vector<int> security = stringToIntegerVector(line);
    getline(cin, line);
    int time = stringToInteger(line);

    vector<int> ret = Solution().goodDaysToRobBank(security, time);

    string out = integerVectorToString(ret);
    cout << out << endl;
  }
  return 0;
}
