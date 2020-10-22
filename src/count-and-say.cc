#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// A(n+1) = 用语言描述的 A(n)
class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) {
            return "";
        }
        if (n == 1) {
            return "1";
        }
        string str = "1";
        ostringstream ss;
        for (int i = 1; i < n; i++) {
            ss.str("");
            for (auto j = str.begin(); j != str.end();) {
                char ch = *j;
                int count = 1;
                for (auto k = j + 1; k != str.end() && *k == *j; k++) {
                    count++;
                }
                ss << count << ch;
                j += count;
            }
            str = ss.str();
        }
        return str;
    }
};

int main() {
    Solution s;
    for (int i = 0; i < 50; i++) {
        std::cout << s.countAndSay(i) << std::endl;
    }
    return 0;
}
