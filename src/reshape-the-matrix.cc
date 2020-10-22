#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (!nums.size() || !nums[0].size()) {
            return nums;
        }
        int originR = nums.size(), originC = nums[0].size();
        if (originR * originC != r * c) {
            return nums;
        }

        vector<vector<int>> result(r, vector<int>(c));
        int newY = 0, newX = 0;
        for (int y = 0; y < originR; y++) {
            for (int x = 0; x < originC; x++) {
                result[newY][newX] = nums[y][x];
                if (newX == c - 1) {
                    newX = 0;
                    newY++;
                } else {
                    newX++;
                }
            }
        }

        return result;
    }
};

int main() {
    return 0;
}
