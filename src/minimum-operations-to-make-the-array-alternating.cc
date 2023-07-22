#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    int n = nums.size();

    auto get = [&](int start) -> tuple<int, int, int, int> {
      unordered_map<int, int> freq;
      for (int i = start; i < n; i += 2) {
        ++freq[nums[i]];
      }

      int fstkey = 0, fstval = 0, sndkey = 0, sndval = 0;
      for (const auto &[key, val] : freq) {
        if (val > fstval) {
          tie(sndkey, sndval) = tuple{fstkey, fstval};
          tie(fstkey, fstval) = tuple{key, val};
        } else if (val > sndval) {
          tie(sndkey, sndval) = tuple{key, val};
        }
      }

      return {fstkey, fstval, sndkey, sndval};
    };

    auto [e1stkey, e1stval, e2ndkey, e2ndval] = get(0);
    auto [o1stkey, o1stval, o2ndkey, o2ndval] = get(1);

    if (e1stkey != o1stkey) {
      return n - (e1stval + o1stval);
    }

    return n - max(e1stval + o2ndval, o1stval + e2ndval);
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
    vector<int> nums = stringToIntegerVector(line);

    int ret = Solution().minimumOperations(nums);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
