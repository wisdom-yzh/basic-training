#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = 0;
        while (n > 0) {
            num++;
            n &= (n - 1);
        }
        return num;
    }
};

int main() {
    cout << Solution().hammingWeight(11) << endl;
    return 0;
}
