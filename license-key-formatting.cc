#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        std::string result;

        for (auto i = S.rbegin(); i != S.rend(); i++) {
            if (*i == '-') {
                continue;
            }
            if ((result.size() % (K + 1)) == K) {
                result += '-';
            }
            result += std::toupper(*i);
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    std::cout << Solution().licenseKeyFormatting("5F3Z-2e-9-w", 4);
    std::cout << Solution().licenseKeyFormatting("2-5g-3-J", 2);
    return 0;
}
