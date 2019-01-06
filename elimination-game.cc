#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        int t = n >> 1;
        return n == 1 ? 1 : (t + 1 - lastRemaining(t)) << 1;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().lastRemaining(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
