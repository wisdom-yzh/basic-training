#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
    vector<int> arrive(dist.size(), 0);
    for (int i = 0; i < dist.size(); i++) {
      arrive[i] = ((dist[i] % speed[i]) == 0) ? (dist[i] / speed[i])
                                              : ((dist[i] / speed[i]) + 1);
    }

    std::sort(arrive.begin(), arrive.end());

    int res{0}, i{0}, total = arrive.size();
    while (res < total) {
      if (res >= arrive[i]) {
        break;
      }
      i++;
      res++;
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

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> dist = stringToIntegerVector(line);
    getline(cin, line);
    vector<int> speed = stringToIntegerVector(line);

    int ret = Solution().eliminateMaximum(dist, speed);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
