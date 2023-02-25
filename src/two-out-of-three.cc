#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2,
                            vector<int> &nums3) {
    std::unordered_map<int, std::set<int>> map;
    for (const auto &num : nums1) {
      map[num].emplace(1);
    }
    for (const auto &num : nums2) {
      map[num].emplace(2);
    }
    for (const auto &num : nums3) {
      map[num].emplace(3);
    }

    vector<int> res;
    for (const auto &[k, v] : map) {
      if (v.size() >= 2) {
        res.push_back(k);
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

string integerVectorToString(vector<int> list, int length = -1) {
  if (length == -1) {
    length = list.size();
  }

  if (length == 0) {
    return "[]";
  }

  string result;
  for (int index = 0; index < length; index++) {
    int number = list[index];
    result += to_string(number) + ", ";
  }
  return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> nums1 = stringToIntegerVector(line);
    getline(cin, line);
    vector<int> nums2 = stringToIntegerVector(line);
    getline(cin, line);
    vector<int> nums3 = stringToIntegerVector(line);

    vector<int> ret = Solution().twoOutOfThree(nums1, nums2, nums3);

    string out = integerVectorToString(ret);
    cout << out << endl;
  }
  return 0;
}
