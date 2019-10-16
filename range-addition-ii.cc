#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int x = m, y = n;
        for (const auto &op: ops) {
            x = std::min(x, op[0]);
            y = std::min(y, op[1]);
        }
        return x * y;
    }
};

int main() {
    return 0;
}
