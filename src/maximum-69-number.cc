#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        string s = std::to_string(num);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '6') {
                s[i] = '9';
                break;
            }
        }
        return std::stoi(s);
    }
};

int main() {
    vector<int> testCases { 9669, 9996, 9999 };
    for (auto &num: testCases) {
        cout << Solution().maximum69Number(num) << endl;
    }
    return 0;
}
