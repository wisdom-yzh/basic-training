#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        std::stack<int> s;
        s.push(1);
        istringstream iss(preorder);
        string str;
        while (getline(iss, str, ',')) {
            if (s.empty()) {
                return false;
            }
            s.top()--;
            if (s.top() == 0) {
                s.pop();
            }
            if (str != "#") {
                s.push(2);
            }
        }
        return s.empty();
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (size_t i = 1; i < input.length() -1; i++) {
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string preorder = stringToString(line);
        
        bool ret = Solution().isValidSerialization(preorder);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
