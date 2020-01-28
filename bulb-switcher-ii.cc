#include <iostream>
using namespace std;

class Solution {
public:
    int flipLights(int n, int m) {
        if (n == 0) return 0;
        if (n >= 1 && m == 0) return 1;
        if (n == 1) return 2;
        if (n == 2 && m == 1) return 3;
        if (n == 2 && m > 1) return 4;
        if (n >= 3 && m == 1) return 4;
        if (n >= 3 && m == 2) return 7;
        return 8;
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
            int m = stringToInteger(line);

            int ret = Solution().flipLights(n, m);

            string out = to_string(ret);
            cout << out << endl;
        }
    return 0;
}
