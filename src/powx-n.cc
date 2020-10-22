#include <iostream>
#include <utility>
#include <limits>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        const double eps = std::numeric_limits<double>::epsilon();
        if (x > 1.0 - eps && x < 1.0 + eps) {
            return 1;
        }
        if (x > -1.0 - eps && x < -1.0 + eps) {
            return ((n & 1) == 0) ? 1 : -1;
        }
        if (n < 0) {
            if (std::numeric_limits<int>::min() == n) {
                return 0;
            }
            n = -n;
            x = 1 / x;
        }
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        if ((n & 1) == 0) {
            return myPow(x * x, n >> 1);
        }

        return x *  myPow(x, n - 1);
    }
};

int main() {
    Solution s;
    cout << s.myPow(-1.00000, 2147483647) << endl;
    cout << s.myPow(2.00000, -2147483648) << endl;
    cout << s.myPow(2.00000, 10) << endl;
    cout << s.myPow(2.10000, 3) << endl;
    cout << s.myPow(2.00000, -2) << endl;
    return 0;
}
