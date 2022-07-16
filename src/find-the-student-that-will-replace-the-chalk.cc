#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
  int chalkReplacer(vector<int> &chalk, int k) {
    uint64_t sum{0};
    for (auto &c : chalk) {
      sum += c;
    }

    k = k % sum;
    int idx = 0;
    while (k > 0) {
      k -= chalk[idx];
      if (k < 0) {
        break;
      }
      idx++;
    }
    return idx;
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

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> chalk = stringToIntegerVector(line);
    getline(cin, line);
    int k = stringToInteger(line);

    int ret = Solution().chalkReplacer(chalk, k);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
