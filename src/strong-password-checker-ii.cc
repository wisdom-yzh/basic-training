#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

// It has at least 8 characters.
// It contains at least one lowercase letter.
// It contains at least one uppercase letter.
// It contains at least one digit.
// It contains at least one special character. The special characters are the
// characters in the following string: "!@#$%^&*()-+". It does not contain 2 of
// the same character in adjacent positions (i.e., "aab" violates this
// condition, but "aba" does not).
class Solution {
public:
  bool strongPasswordCheckerII(string password) {
    if (password.size() < 8) {
      return false;
    }

    const string specialChars{"!@#$%^&*()-+"};
    bool containsLowerCase = false, containsUppserCase = false,
         containsDigit = false, containsSpecial = false;

    for (int i = 0; i < password.size(); i++) {
      if (i != password.size() - 1 && password[i] == password[i + 1]) {
        return false;
      }

      if (password[i] >= 'a' && password[i] <= 'z') {
        containsLowerCase = true;
      }
      if (password[i] >= 'A' && password[i] <= 'Z') {
        containsUppserCase = true;
      }
      if (password[i] >= '0' && password[i] <= '9') {
        containsDigit = true;
      }
      if (specialChars.find(password[i]) != std::string::npos) {
        containsSpecial = true;
      }
    }

    return containsDigit && containsSpecial && containsLowerCase &&
           containsUppserCase;
  }
};

int main(int argc, char *argv[]) {
  vector<string> testCases{"IloveLe3tcode!", "Me+You--IsMyDream", "1aB!"};
  for (auto &testCase : testCases) {
    cout << boolalpha << Solution().strongPasswordCheckerII(testCase) << endl;
  }
  return 0;
}
