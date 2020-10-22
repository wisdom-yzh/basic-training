#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m <= 0) {
            return 0;
        }
        int bm = static_cast<int>(log2(m));
        int bn = static_cast<int>(log2(n));
        if (bm != bn) {
            return 0;
        }
        int t = bm == 0 ? 1 : (2 << (bm - 1));
        return t + rangeBitwiseAnd(m - t, n - t);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        int ret = Solution().rangeBitwiseAnd(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
