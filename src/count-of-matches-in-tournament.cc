#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        return n - 1;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().numberOfMatches(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
