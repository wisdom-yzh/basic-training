#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> maxSubsequence(vector<int> &nums, int k) {
    auto cmp = [](auto &a, auto &b) { return a.first < b.first; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(
        cmp);
    for (int i = 0; i < nums.size(); i++) {
      q.emplace(nums[i], i);
    }

    vector<int> indexes;
    for (int i = 0; i < k; i++) {
      const auto [_, index] = q.top();
      indexes.push_back(index);
      q.pop();
    }

    sort(indexes.begin(), indexes.end());
    vector<int> res;
    for (auto &i : indexes) {
      res.push_back(nums[i]);
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
    vector<int> nums = stringToIntegerVector(line);
    getline(cin, line);
    int k = stringToInteger(line);

    vector<int> ret = Solution().maxSubsequence(nums, k);

    string out = integerVectorToString(ret);
    cout << out << endl;
  }
  return 0;
}
