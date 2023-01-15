#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int finalValueAfterOperations(vector<string> &operations) {
    int x = 0;
    for (const auto &op : operations) {
      if (op == "X--"sv || op == "--X"sv) {
        x--;
      } else {
        x++;
      }
    }
    return x;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<string>> testCases{
      {"--X", "X++", "X++"},
      {"++X", "++X", "X++"},
      {"X++", "++X", "--X", "X--"},
  };

  for (auto &testCase : testCases) {
    cout << Solution().finalValueAfterOperations(testCase) << endl;
  }

  return 0;
}
