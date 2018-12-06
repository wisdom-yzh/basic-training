#include <iostream>
#include <string>
using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num) {
    return true;
}

class Solution {
public:
    int guessNumber(int n) {
        int p = 1, q = n;
        while (true) {
            int mid = p + (q - p) / 2;
            int g = guess(mid);
            if (g == 0) {
                return mid;
            } else if (g == -1) {
                q = mid - 1;
            } else {
                p = mid + 1;
            }
        }
    }
};

int main() {
    return 0;
}
