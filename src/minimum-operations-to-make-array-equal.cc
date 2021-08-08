#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int minOperations(int n) {
        return n * n / 4;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().minOperations(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
