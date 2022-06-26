#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> memLeak(int memory1, int memory2) {
    int i = 1;
    while (memory1 >= i || memory2 >= i) {
      if (memory1 >= memory2) {
        memory1 -= i;
      } else {
        memory2 -= i;
      }
      i++;
    }
    return vector<int>{i, memory1, memory2};
  }
};

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
    int memory1 = stringToInteger(line);
    getline(cin, line);
    int memory2 = stringToInteger(line);

    vector<int> ret = Solution().memLeak(memory1, memory2);

    string out = integerVectorToString(ret);
    cout << out << endl;
  }
  return 0;
}
