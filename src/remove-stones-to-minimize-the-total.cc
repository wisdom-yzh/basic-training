#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
  int minStoneSum(vector<int> &piles, int k) {
    std::priority_queue<int> pq;
    for (auto &p : piles) {
      pq.push(p);
    }

    for (int i = 0; i < k; i++) {
      auto x = pq.top();
      pq.pop();
      pq.push((x + 1) / 2);
    }

    int res = 0;
    while (!pq.empty()) {
      res += pq.top();
      pq.pop();
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
    vector<int> piles = stringToIntegerVector(line);
    getline(cin, line);
    int k = stringToInteger(line);

    int ret = Solution().minStoneSum(piles, k);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
