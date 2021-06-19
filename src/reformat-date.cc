#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    string reformatDate(string date) {
        istringstream ss;
        ss.str(date);

        string m, d, y;
        getline(ss, d, ' ');
        getline(ss, m, ' ');
        getline(ss, y, ' ');

        const static vector<string> M = {
            "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
        };

        return y + "-" +
            T(to_string(1 + distance(M.begin(), std::find(M.begin(), M.end(), m)))) + "-" +
            T(d.substr(0, distance(d.begin(), std::find_if(d.begin(), d.end(), [] (char &ch) {
                return !(ch >= '0' && ch <= '9');
            }))));
    }

    string T(string &&x) {
        if (x.size() == 1) {
            return "0" + x;
        }
        return string(x);
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
        string date = stringToString(line);

        string ret = Solution().reformatDate(date);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
