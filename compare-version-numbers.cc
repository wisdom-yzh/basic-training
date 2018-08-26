#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cmath>
using namespace std;

class Solution {
public:
    void split(string &version, vector<int> &arr) {
        istringstream iss;
        iss.str(version);
        string s;
        while (getline(iss, s, '.')) {
            arr.push_back(std::stoi(s));
        }
    }

    int compareVersion(string version1, string version2) {
        vector<int> arr1, arr2;
        this->split(version1, arr1);
        this->split(version2, arr2);
        auto &shortArr = arr1.size() > arr2.size() ? arr2 : arr1;
        auto diffLen = abs((int)arr1.size() - (int)arr2.size());
        for (int i = 0; i < diffLen; i++) {
            shortArr.push_back(0);
        }

        for (int i = 0; i < arr1.size(); i++) {
            if (arr1[i] == arr2[i]) {
                continue;
            }
            return arr1[i] > arr2[i] ? 1 : -1;
        }

        return 0;
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
        string version1 = stringToString(line);
        getline(cin, line);
        string version2 = stringToString(line);

        int ret = Solution().compareVersion(version1, version2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
