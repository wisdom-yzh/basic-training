#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        std::reverse(s.begin(), s.end());
        auto p = s.begin();
        bool start = false;
        ostringstream oss;
        for (auto q = s.begin(); q != s.end(); q++) {
            if (!start) {
                if (*q != ' ') {
                    start = true;
                    p = q;
                }
            }
            if (start) {
                if (*q == ' ') {
                    std::reverse(p, q);
                    if (!oss.str().empty()) {
                        oss << ' ';
                    }
                    oss << string(p, q);
                    start = false;
                } else if (q == s.end() - 1) {
                    std::reverse(p, q + 1);
                    if (!oss.str().empty()) {
                        oss << ' ';
                    }
                    oss << string(p, q + 1);
                }
            }
        }
        s.assign(oss.str());
    }
};

int main() {
    string s("the sky is blue");
    Solution().reverseWords(s);
    cout << s << endl;
    s.assign(" ");
    Solution().reverseWords(s);
    cout << s << endl;
    s.assign(" a    b  ");
    Solution().reverseWords(s);
    cout << s << endl;
    s.assign("a    ");
    Solution().reverseWords(s);
    cout << s << endl;
    s.assign("    a");
    Solution().reverseWords(s);
    cout << s;
    return 0;
}
