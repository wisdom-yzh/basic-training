#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
    std::sort(arr.begin(), arr.end());
    arr[0] = 1;

    for (int i = 1; i < arr.size(); i++) {
      if (arr[i] > arr[i - 1] + 1) {
        arr[i] = arr[i - 1] + 1;
      }
    }

    return arr.back();
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
    vector<int> arr = stringToIntegerVector(line);

    int ret = Solution().maximumElementAfterDecrementingAndRearranging(arr);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
