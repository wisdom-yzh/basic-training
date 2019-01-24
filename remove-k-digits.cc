#include <string>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string result(std::move(num));
        for (int i = 0; i < k; i++) {
            removeDigit(result);
        }
        int count = result.find_first_not_of("0");
        if (count > 0) {
            result.erase(0, count);
        }
        if (count == -1 || result.empty()) {
            result.assign("0");
        }
        return result;
    }

    void removeDigit(string &num) {
        int removeIndex = -1;
        for (size_t i = 0; i < num.size() - 1; i++) {
            if (num[i] > num[i + 1]) {
                removeIndex = i;
                break;
            }
        }
        if (removeIndex == -1) {
            removeIndex = num.size() - 1;
        }
        num.erase(removeIndex, 1);
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string num = stringToString(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        string ret = Solution().removeKdigits(num, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
