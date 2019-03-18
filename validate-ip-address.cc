#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {
        if (isIPV4(IP)) {
            return "IPV4";
        }
        if (isIPV6(IP)) {
            return "IPV6";
        }
        return "Neither";
    }

    bool isIPV4(const string &IP) {
        int seriesCount = 0;
        std::string series;

        std::istringstream iss(IP);
        while (std::getline(iss, series, '.')) {
            if (series.length() == 0) {
                return false;
            }
            int num = 0;
            bool firstZero = false;
            for (const char &ch: series) {
                if (ch >= '0' && ch <= '9') {
                    num *= 10;
                    num += ch - '0';
                    if (firstZero) {
                        return false;
                    }
                    if (num == 0) {
                        firstZero = true;
                    }
                } else {
                    return false;
                }
                if (num > 255) {
                    return false;
                }
            }
            seriesCount++;
        }

        if (IP[IP.length() - 1] == '.') {
            return false;
        }

        return seriesCount == 4;
    }

    bool isIPV6(const string &IP) {
        int seriesCount = 0;
        std::string series;

        std::istringstream iss(IP);
        while (std::getline(iss, series, ':')) {
            if (series.length() == 0 || series.length() > 4) {
                return false;
            }
            for (const char &ch: series) {
                if ((ch >= '0' && ch <= '9') ||
                    (ch >= 'a' && ch <= 'f') ||
                    (ch >= 'A' && ch <= 'F')) {
                    continue;
                }
                return false;
            }
            seriesCount++;
        }

        if (IP[IP.length() - 1] == ':') {
            return false;
        }

        return seriesCount == 8;
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
        string IP = stringToString(line);

        string ret = Solution().validIPAddress(IP);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
