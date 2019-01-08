#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        string ret;
        auto n = static_cast<uint32_t>(num);
        while (n > 0) {
            int x = n % 16;
            if (x < 10) {
                ret.push_back(x + '0');
            } else {
                ret.push_back(x - 10 + 'a');
            }
            n /= 16;
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        string ret = Solution().toHex(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
