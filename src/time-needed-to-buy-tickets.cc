#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
  int timeRequiredToBuy(vector<int> &tickets, int k) {
    int res = 0;
    for (int i = 0; i < tickets.size(); ++i) {
      if (i <= k) {
        res += min(tickets[i], tickets[k]);
      } else {
        res += min(tickets[i], tickets[k] - 1);
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

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> tickets = stringToIntegerVector(line);
    getline(cin, line);
    int k = stringToInteger(line);

    int ret = Solution().timeRequiredToBuy(tickets, k);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
