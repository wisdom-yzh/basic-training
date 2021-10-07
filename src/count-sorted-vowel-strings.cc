#include <iostream>
using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 4 / 3 / 2 / 1;
    }
};

int main() {
    for (int i = 1; i <= 33; i++) {
        cout << Solution().countVowelStrings(i) << endl;
    }
    return 0;
}
