#include <algorithm>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        char set1[2], set2[2];
        int count = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (count >= 2) {
                    return false;
                }
                set1[count] = s1[i];
                set2[count] = s2[i];
                count++;
            }
        }
        return count == 0 || ((count == 2) &&
            (set1[0] == set2[0] && set1[1] == set2[1]) ||
            (set1[0] == set2[1] && set1[1] == set2[0]));
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s1 = stringToString(line);
        getline(cin, line);
        string s2 = stringToString(line);
        
        bool ret = Solution().areAlmostEqual(s1, s2);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
