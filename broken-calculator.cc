#include <vector>
#include <iostream>
#include <limits>
#include <map>
#include <cmath>
using namespace std;

class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        while (Y > X) {
            ans++;
            if (Y % 2 == 1)
                Y++;
            else
                Y /= 2;
        }
        return ans + X - Y;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int X = stringToInteger(line);
        getline(cin, line);
        int Y = stringToInteger(line);

        int ret = Solution().brokenCalc(X, Y);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
