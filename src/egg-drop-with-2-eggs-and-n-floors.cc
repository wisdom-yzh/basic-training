#include <iostream>
using namespace std;

class Solution {
public:
  int twoEggDrop(int n) {
    int sum = 0;
    int index = 0;
    for (int i = 1; sum < n; i++) {
      sum += i;
      index = i;
    }
    return index;
  }
};

int stringToInteger(string input) { return stoi(input); }

int main() {
  string line;
  while (getline(cin, line)) {
    int n = stringToInteger(line);

    int ret = Solution().twoEggDrop(n);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
