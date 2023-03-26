#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
  int minimizedMaximum(int n, vector<int> &quantities) {
    int l = 1, r = *max_element(quantities.begin(), quantities.end());
    while (l < r) {
      int mid = (l + r) >> 1;
      int cnt = 0;
      for (int q : quantities) {
        cnt += (q + mid - 1) / mid;
      }
      if (cnt > n) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l;
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

int main() {
  string line;
  while (getline(cin, line)) {
    int n = stringToInteger(line);
    getline(cin, line);
    vector<int> quantities = stringToIntegerVector(line);

    int ret = Solution().minimizedMaximum(n, quantities);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
