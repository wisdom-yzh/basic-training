#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countOperations(int num1, int num2) {
    if (num1 == 0 || num2 == 0) {
      return 0;
    }

    if (num1 == num2) {
      return 1;
    }

    if (num1 > num2) {
      return 1 + countOperations(num1 - num2, num2);
    }

    return 1 + countOperations(num2 - num1, num1);
  }
};

int stringToInteger(string input) { return stoi(input); }

int main() {
  string line;
  while (getline(cin, line)) {
    int num1 = stringToInteger(line);
    getline(cin, line);
    int num2 = stringToInteger(line);

    int ret = Solution().countOperations(num1, num2);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
