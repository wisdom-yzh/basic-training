#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int res = 0;

        for (int i = 0; i < n; i++) {
            res ^= start;
            start += 2;
        }

        return res;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int start = stringToInteger(line);

        int ret = Solution().xorOperation(n, start);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
