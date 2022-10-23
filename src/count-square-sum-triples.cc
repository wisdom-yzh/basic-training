#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int countTriples(int n) {
    int count{0};
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        for (int k = std::max(i, j); k <= n; k++) {
          auto x = i * i + j * j;
          if (x == k * k) {
            count++;
            break;
          } else if (x < k * k) {
            break;
          }
        }
      }
    }
    return count;
  }
};

int stringToInteger(string input) { return stoi(input); }

int main() {
  string line;
  while (getline(cin, line)) {
    int n = stringToInteger(line);

    int ret = Solution().countTriples(n);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
