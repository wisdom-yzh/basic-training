#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    Solution(vector<vector<int>>& rects): rects(rects) {}

    vector<int> pick() {
        int sumArea = 0;
        vector<int> selected;

        for (auto &r : rects) {
            int area = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            sumArea += area;

            if (rand() % sumArea < area) {
                selected = r;
            }
        }

        int x = rand() % (selected[2] - selected[0] + 1) + selected[0];
        int y = rand() % (selected[3] - selected[1] + 1) + selected[1];
        return { x, y };
    }

private:
    vector<vector<int>> rects;
};

int main() {
    return 0;
}
