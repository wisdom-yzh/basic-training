#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool asteroidsDestroyed(int mass, vector<int> &asteroids) {
    int res = mass;
    std::sort(asteroids.begin(), asteroids.end());
    for (int i = 0; i < asteroids.size(); i++) {
      if (res < asteroids[i]) {
        return false;
      }
      res += asteroids[i];
    }
    return true;
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

string boolToString(bool input) { return input ? "True" : "False"; }

int main() {
  string line;
  while (getline(cin, line)) {
    int mass = stringToInteger(line);
    getline(cin, line);
    vector<int> asteroids = stringToIntegerVector(line);

    bool ret = Solution().asteroidsDestroyed(mass, asteroids);

    string out = boolToString(ret);
    cout << out << endl;
  }
  return 0;
}
