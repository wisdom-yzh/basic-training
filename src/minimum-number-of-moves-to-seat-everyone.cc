#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int minMovesToSeat(vector<int> &seats, vector<int> &students) {
    std::sort(seats.begin(), seats.end());
    std::sort(students.begin(), students.end());
    int res{0};
    for (int i = 0; i < seats.size(); i++) {
      res += std::abs(seats[i] - students[i]);
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
    vector<int> seats = stringToIntegerVector(line);
    getline(cin, line);
    vector<int> students = stringToIntegerVector(line);

    int ret = Solution().minMovesToSeat(seats, students);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
