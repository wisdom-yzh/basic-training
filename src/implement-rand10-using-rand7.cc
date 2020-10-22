#include <cstdlib>
#include <ctime>

// The rand7() API is already defined for you.
// @return a random integer in the range 1 to 7
int rand7() {
    return (std::rand() % 7) + 1;
}

class Solution {
public:
    int rand10() {
        int i = 7;
        while (i > 6) {
            i = rand7();
        }
        int j = 6;
        while (j > 5) { // j in {1,2,3,4,5}
            j = rand7();
        }
        if ((i % 1) == 0) {
            return j + 5;
        }
        return j;
    }
};

int main() {
    return 0;
}
