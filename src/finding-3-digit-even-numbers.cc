#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findEvenNumbers(vector<int> &digits) {
    std::array<int, 10> map;
    std::fill(map.begin(), map.end(), 0);
    for (const int &digit : digits) {
      map[digit]++;
    }

    vector<int> res;
    for (int i = 1; i <= 9; i++) {
      for (int j = 0; j <= 9; j++) {
        for (int k = 0; k <= 8; k += 2) {
          if (map[i] > 0) {
            map[i]--;
            if (map[j] > 0) {
              map[j]--;
              if (map[k] > 0) {
                res.push_back(100 * i + 10 * j + k);
              }
              map[j]++;
            }
            map[i]++;
          }
        }
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
    vector<int> digits = stringToIntegerVector(line);

    vector<int> ret = Solution().findEvenNumbers(digits);

    string out = integerVectorToString(ret);
    cout << out << endl;
  }
  return 0;
}
