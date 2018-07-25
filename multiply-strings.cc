#include <string>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <vector>
#include <sstream>
using namespace std;

const unsigned long long BASE_NUMBER = 100000000;
const unsigned int BASE_LENGTH = 8;

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<unsigned long long> arrNum1, arrNum2;
        for (auto posBegin = num1.end() - 1; ; posBegin -= 8) {
            auto posEnd = (posBegin - BASE_LENGTH + 1) < num1.begin() ?
                num1.begin() : (posBegin - BASE_LENGTH + 1);
            arrNum1.push_back(std::stoull(string(posEnd, posBegin + 1)));
            if (posEnd == num1.begin()) {
                break;
            }
        }
        for (auto posBegin = num2.end() - 1; ; posBegin -= 8) {
            auto posEnd = (posBegin - BASE_LENGTH + 1) < num2.begin() ?
                num2.begin() : (posBegin - BASE_LENGTH + 1);
            arrNum2.push_back(std::stoull(string(posEnd, posBegin + 1)));
            if (posEnd == num2.begin()) {
                break;
            }
        }

        vector<unsigned long long> arrResult(arrNum1.size() + arrNum2.size());
        for (unsigned int i = 0; i < arrNum1.size(); i++) {
            for (unsigned int j = 0; j < arrNum2.size(); j++) {
                arrResult[i + j] += arrNum1[i] * arrNum2[j];
                arrResult[i + j + 1] += arrResult[i + j] / BASE_NUMBER;
                arrResult[i + j] %= BASE_NUMBER;
            }
        }
        
        stringstream ss;
        for (auto iter = arrResult.rbegin(); iter != arrResult.rend(); iter++) {
            ss << setfill('0') << setw(BASE_LENGTH) << (*iter);
        }

        string result = ss.str();
        result.erase(result.begin(), find_if(result.begin(), result.end(), [](char ch) {
            return ch != '0';
        }));
        return result.empty() ? "0" : result;
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
        string num1 = stringToString(line);
        getline(cin, line);
        string num2 = stringToString(line);
        
        string ret = Solution().multiply(num1, num2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
