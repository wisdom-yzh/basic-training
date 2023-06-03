#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumRefill(vector<int> &plants, int capacityA, int capacityB) {
    int left = 0, right = plants.size() - 1;
    int capA = capacityA, capB = capacityB;
    int res = 0;

    while (left <= right) {
      if (left == right) {
        if (capA < plants[left] && capB < plants[right]) {
          res++;
        }
        break;
      }
      if (capA < plants[left]) {
        res++;
        capA = capacityA;
      }
      capA -= plants[left];
      left++;
      if (capB < plants[right]) {
        res++;
        capB = capacityB;
      }
      capB -= plants[right];
      right--;
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
    vector<int> plants = stringToIntegerVector(line);
    getline(cin, line);
    int capacityA = stringToInteger(line);
    getline(cin, line);
    int capacityB = stringToInteger(line);

    int ret = Solution().minimumRefill(plants, capacityA, capacityB);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
