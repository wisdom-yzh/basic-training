#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        stringstream ss;
        bool lessThanZero = num < 0;
        uint64_t n = static_cast<uint64_t>(lessThanZero ? -num : num);

        while (n != 0) {
            ss << (n % 7);
            n /= 7;
        }

        string symbol(lessThanZero ? "-" : "");
        string strNum(ss.str());
        std::reverse(strNum.begin(), strNum.end());
        return symbol + strNum;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        string ret = Solution().convertToBase7(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
