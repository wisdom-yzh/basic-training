#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
  int findGCD(vector<int> &nums) {
    int minElem = std::numeric_limits<int>::max(),
        maxElem = std::numeric_limits<int>::min();
    for (auto &num : nums) {
      minElem = std::min(minElem, num);
      maxElem = std::max(maxElem, num);
    }
    return gcd(maxElem, minElem);
  }

  int gcd(int a, int b) {
    if ((a % b) == 0) {
      return b;
    }
    return gcd(b, a % b);
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

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> nums = stringToIntegerVector(line);

    int ret = Solution().findGCD(nums);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
