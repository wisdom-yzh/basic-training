#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
using namespace std;

class Solution {
public:
    string toGoatLatin(string S) {
        string word;
        istringstream iss(S);
        ostringstream oss;
        int index = 1;

        while (getline(iss, word, ' ')) {
            char ch = std::tolower(word[0]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                oss << word << "ma";
            } else {
                oss << word.substr(1) << word[0] << "ma";
            }

            for (int i = 0; i < index; i++) {
                oss << 'a';
            }
            oss << ' ';
            index++;
        }

        auto result = oss.str();
        return result.substr(0, result.size() - 1);
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
        string S = stringToString(line);

        string ret = Solution().toGoatLatin(S);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
