#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findOriginalArray(vector<int> &changed) {
    int size = changed.size();
    if ((size % 2) == 1) {
      return vector<int>{};
    }

    std::map<int, int> dict;
    for (auto &x : changed) {
      dict[x]++;
    }

    vector<int> res;
    while (size > 0) {
      auto elem = dict.begin();
      res.push_back(elem->first);
      if (elem->second == 1) {
        dict.erase(elem);
      } else {
        elem->second--;
      }

      auto elem2 = dict.find(res.back() * 2);
      if (elem2 == dict.end()) {
        return vector<int>{};
      }
      if (elem2->second == 1) {
        dict.erase(elem2);
      } else {
        elem2->second--;
      }

      size -= 2;
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
    vector<int> changed = stringToIntegerVector(line);

    vector<int> ret = Solution().findOriginalArray(changed);

    string out = integerVectorToString(ret);
    cout << out << endl;
  }
  return 0;
}
