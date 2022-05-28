#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
  int maxIceCream(vector<int> &costs, int coins) {
    std::sort(costs.begin(), costs.end());
    int i = 0;

    while (i < costs.size() && coins >= costs[i]) {
      coins -= costs[i];
      i++;
    }

    return i;
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
    vector<int> costs = stringToIntegerVector(line);
    getline(cin, line);
    int coins = stringToInteger(line);

    int ret = Solution().maxIceCream(costs, coins);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
