#include <iostream>

class Solution {
public:
    int findComplement(int num) {
        uint32_t mask = ~0;
        while (mask & num) {
            mask <<= 1;
        }
        return ~mask & ~num;
    }
};

int main() {
    std::cout << Solution().findComplement(5) << std::endl;
    std::cout << Solution().findComplement(1) << std::endl;
    return 0;
}
