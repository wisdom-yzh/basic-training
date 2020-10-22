#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int t = x ^ y;
        int result = 0;
        while (t != 0) {
            t &= (t - 1);
            result++;
        }
        return result;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        getline(cin, line);
        int y = stringToInteger(line);

        int ret = Solution().hammingDistance(x, y);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
