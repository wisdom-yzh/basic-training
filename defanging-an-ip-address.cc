#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        int pos = 0;
        do {
            pos = address.find('.', pos);
            if (pos == string::npos) {
                break;
            }
            address.replace(pos, 1, "[.]");
            if (pos >= address.size() - 3) {
                break;
            }
            pos += 2;
        } while (true);
        return address;
    }
};

int main() {
    cout << Solution().defangIPaddr("255.100.50.0");
    return 0;
}
