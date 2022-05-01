#include <string>
#include <deque>
#include <iostream>
#include <sstream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        std:deque<string> q1, q2;
        string item;

        stringstream ss1(sentence1);
        while (getline(ss1, item, ' ')) {
            q1.push_back(item);
        }

        stringstream ss2(sentence2);
        while (getline(ss2, item, ' ')) {
            q2.push_back(item);
        }

        while (!q1.empty() && !q2.empty()) {
            if (q1.front() == q2.front()) {
                q1.pop_front();
                q2.pop_front();
            } else if (q1.back() == q2.back()) {
                q1.pop_back();
                q2.pop_back();
            } else {
                return false;
            }
        }

        return q1.empty() || q2.empty();
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
        string sentence1 = stringToString(line);
        getline(cin, line);
        string sentence2 = stringToString(line);
        
        bool ret = Solution().areSentencesSimilar(sentence1, sentence2);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
