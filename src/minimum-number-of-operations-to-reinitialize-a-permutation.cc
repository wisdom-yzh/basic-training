#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> x(n, 0), y(n, 0), *p, *q;
        for (int i = 0; i < n; i++) {
            x[i] = i;
        }

        int res = 1;
        p = &x;
        q = &y;
        for (res = 1; ; res++) {
            auto &borrowX = *p;
            auto &borrowY = *q;
            bool reinitialized = true;
            for (int i = 0; i < n; i++) {
                int value = (i % 2 == 0)
                    ? borrowX[i / 2]
                    : borrowX[n / 2 + (i - 1) / 2];
                borrowY[i] = value;
                if (reinitialized && value != i) {
                    reinitialized = false;
                }
            }
            if (reinitialized) {
                break;
            }
            swap(p, q);
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
        
        int ret = Solution().reinitializePermutation(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
