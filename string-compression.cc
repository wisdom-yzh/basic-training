#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.empty()) {
            return 0;
        }
        int length = 0;
        int duplicate = 1;
        char current = 0;
        for (int i = 0; i < chars.size(); i++) {
            if (chars[i] == current) {
                duplicate++;
            } else {
                if (duplicate > 1) {
                    string s(std::to_string(duplicate));
                    for (auto &ch: s) {
                        chars[length++] = ch;
                    }
                }

                duplicate = 1;
                current = chars[i];
                chars[length++] = current;
            }
        }
        if (duplicate > 1) {
            string s(std::to_string(duplicate));
            for (auto &ch: s) {
                chars[length++] = ch;
            }
        }
        return length;
    }
};

int main() {
    vector<char> chars { 'a', 'a', 'b', 'b', 'c', 'c', 'c' };
    int len = Solution().compress(chars);
    for (int i = 0; i < len; i++) {
        std::cout << chars[i] << ' ';
    }
    return 0;
}
