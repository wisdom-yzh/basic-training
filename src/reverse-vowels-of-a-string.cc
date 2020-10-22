#include <string>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
       int p = 0, q = s.length() - 1; 
       while (p < q) {
            p = getNext(s, p);
            q = getPrev(s, q);
            if (p < q) {
                std::swap(s[p], s[q]);
            }
            p++;
            q--;
       }
       return s;
    }

    int getNext(string &s, int p) {
        while (p < s.length() && !isVowels(s[p])) {
            p++;
        }
        return p;
    }

    int getPrev(string &s, int q) {
        while (q > 0 && !isVowels(s[q])) {
            q--;
        }
        return q;
    }

    bool isVowels(char ch) {
        static string vowels = "aeiouAEIOU";
        return vowels.find(ch, 0) != string::npos;
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
        string s = stringToString(line);

        string ret = Solution().reverseVowels(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
