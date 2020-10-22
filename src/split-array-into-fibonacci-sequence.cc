#include <vector>
#include <string>
#include <cassert>
#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        for (int i = 1; i < std::min(10, (int)S.size() - 1); i++) {
            if (i > 1 && S[0] == '0') {
                break;
            }

            for (int j = 1; j < std::min(10, (int)S.size() - 1 - i); j++) {
                if (j > 1 && S[i] == '0') {
                    break;
                }

                int first = std::stol(S.substr(0, i));  // [0, i-1]
                int second = std::stol(S.substr(i, j)); // [i, i+j-1]
                vector<int> result { first, second };
                if (check(result, S.substr(i + j))) {
                    return result;
                }
            }
        }

        return {};
    }

    bool check(vector<int> &fib, string &&S) {
        int index = 0;
        while (!S.empty()) {
            long next = (long)fib[index] + fib[index + 1];
            if (next > std::numeric_limits<int>::max()) {
                return false;
            }

            string nextStr = std::to_string(next);
            if (nextStr.size() > S.size() || nextStr != S.substr(0, nextStr.size())) {
                return false;
            }

            S = S.substr(nextStr.size());
            fib.push_back(next);
            index++;
        }
        return true;
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
        string S = stringToString(line);

        vector<int> ret = Solution().splitIntoFibonacci(S);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
