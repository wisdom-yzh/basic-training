#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res(boxes.size(), 0);

        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res.size(); j++) {
                if (boxes[j] == '1') {
                    res[i] += std::abs(i - j);
                }
            }
        }

        return res;
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string boxes = stringToString(line);
        
        vector<int> ret = Solution().minOperations(boxes);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
