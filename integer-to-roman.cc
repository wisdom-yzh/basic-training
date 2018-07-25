#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

class Solution {
public:

    void getNumberBit(ostringstream &ss, int numBit, int bitIndex) {
        static const char mapTable[4][3] = {
            { 'I', 'V', 'X' },
            { 'X', 'L', 'C' },
            { 'C', 'D', 'M' },
            { 'M'           }
        };

        if (numBit == 9) {
            ss << mapTable[bitIndex][0] << mapTable[bitIndex][2];
        } else if (numBit > 5 && numBit < 9) {
            ss << mapTable[bitIndex][1] << string(numBit - 5, mapTable[bitIndex][0]);
        } else if (numBit == 5) {
            ss << mapTable[bitIndex][1];
        } else if (numBit == 4) {
            ss << mapTable[bitIndex][0] << mapTable[bitIndex][1];
        } else if (numBit > 0) {
            ss << string(numBit, mapTable[bitIndex][0]);
        }
    }

    string intToRoman(int num) {
        ostringstream ss;

        int bitIndex = 0;
        if (num >= 1000) {
            bitIndex = 3;
        } else if (num >= 100) {
            bitIndex = 2;
        } else if (num >= 10) {
            bitIndex = 1;
        }
        while (num >= 10) {
            int r = std::pow(10, bitIndex);
            int numBit = num / r;
            this->getNumberBit(ss, numBit, bitIndex);
            num -= (numBit * r);
            bitIndex--;
        }
        this->getNumberBit(ss, num, 0);

        return ss.str();
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);
        
        string ret = Solution().intToRoman(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
