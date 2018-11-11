#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().bulbSwitch(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
