#include <cassert>
using namespace std;

class Solution {
public:
    bool divisorGame(int N) {
        return !(N & 1);
    }
};

int main() {
    assert(Solution().divisorGame(2));
    assert(!Solution().divisorGame(3));
    return 0;
}
