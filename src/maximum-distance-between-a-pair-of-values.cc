#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxDistance(vector<int> &nums1, vector<int> &nums2) {
    int ans{0};
    for (int i = 0; i < nums1.size(); i++) {
      while (i + ans < nums2.size() && nums2[i + ans] >= nums1[i]) {
        ans++;
      }
    }
    return ans == 0 ? 0 : ans - 1;
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
    vector<int> nums1 = stringToIntegerVector(line);
    getline(cin, line);
    vector<int> nums2 = stringToIntegerVector(line);

    int ret = Solution().maxDistance(nums1, nums2);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
