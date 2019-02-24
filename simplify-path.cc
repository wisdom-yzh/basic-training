#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
#include <iterator>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        istringstream ss(path);
        string item;
        vector<string> dirList;
        while (std::getline(ss, item, '/')) {
            dirList.push_back(item);
        }

        vector<string> simplifyDirList;
        for (auto iter = dirList.begin(); iter != dirList.end(); iter++) {
            string dir = *iter;
            if (dir.empty() || dir == ".") {
                continue;
            } else if (dir == "..") {
                if (!simplifyDirList.empty()) {
                    simplifyDirList.pop_back();
                }
            } else {
                simplifyDirList.push_back(dir);
            }
        }

        ostringstream oss;
        oss << "/";
        if (!simplifyDirList.empty()) {
            std::copy(
                simplifyDirList.begin(),
                simplifyDirList.end() - 1,
                ostream_iterator<string>(oss, "/")
            );
            oss << *(simplifyDirList.end() - 1);
        }
        return oss.str();
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (unsigned int i = 1; i < input.length() -1; i++) {
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
        string path = stringToString(line);

        string ret = Solution().simplifyPath(path);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
