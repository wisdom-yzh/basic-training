#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class Solution {
public:
    string maximumTime(string time) {
        if (time[0] == '?') {
            time[0] = (time[1] != '?' && time[1] >= '4') ? '1' : '2';
        }

        if (time[1] == '?') {
            time[1] = time[0] == '2' ? '3' : '9';
        }

        if (time[3] == '?') {
            time[3] = '5';
        }

        if (time[4] == '?') {
            time[4] = '9';
        }

        return time;
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

int main() {
    string line;
    while (getline(cin, line)) {
        string time = stringToString(line);

        string ret = Solution().maximumTime(time);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
