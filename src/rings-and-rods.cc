#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countPoints(string rings) {
    std::array<int, 10> arr;
    std::fill(arr.begin(), arr.end(), 0);

    for (int i = 0; i < rings.size(); i += 2) {
      int x = rings[i + 1] - '0';
      switch (rings[i]) {
      case 'R':
        arr[x] |= 0b001;
        break;
      case 'G':
        arr[x] |= 0b010;
        break;
      case 'B':
        arr[x] |= 0b100;
        break;
      }
    }

    int res{0};
    for (auto &x : arr) {
      if (x == 0b111) {
        res++;
      }
    }
    return res;
  }
};

string stringToString(string input) {
  assert(input.length() >= 2);
  string result;
  for (int i = 1; i < input.length() - 1; i++) {
    char currentChar = input[i];
    if (input[i] == '\\') {
      char nextChar = input[i + 1];
      switch (nextChar) {
      case '\"':
        result.push_back('\"');
        break;
      case '/':
        result.push_back('/');
        break;
      case '\\':
        result.push_back('\\');
        break;
      case 'b':
        result.push_back('\b');
        break;
      case 'f':
        result.push_back('\f');
        break;
      case 'r':
        result.push_back('\r');
        break;
      case 'n':
        result.push_back('\n');
        break;
      case 't':
        result.push_back('\t');
        break;
      default:
        break;
      }
      i++;
    } else {
      result.push_back(currentChar);
    }
  }
  return result;
}

int main() {
  string line;
  while (getline(cin, line)) {
    string rings = stringToString(line);

    int ret = Solution().countPoints(rings);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
