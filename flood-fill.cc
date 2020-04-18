#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor == newColor) {
            return image;
        }
        image[sr][sc] = newColor;
        std::queue<std::pair<int, int>> q;
        q.push(std::make_pair(sr, sc));

        while (!q.empty()) {
            int r, c;
            std::tie(r, c) = q.front();

            if (r > 0 && image[r - 1][c] == oldColor) {
                image[r - 1][c] = newColor;
                q.push(make_pair(r - 1, c));
            }
            if (r < image.size() - 1 && image[r + 1][c] == oldColor) {
                image[r + 1][c] = newColor;
                q.push(make_pair(r + 1, c));
            }
            if (c > 0 && image[r][c - 1] == oldColor) {
                image[r][c - 1] = newColor;
                q.push(make_pair(r, c - 1));
            }
            if (c < image[0].size() - 1 && image[r][c + 1] == oldColor) {
                image[r][c + 1] = newColor;
                q.push(make_pair(r, c + 1));
            }

            q.pop();
        }

        return image;
    }
};

int main() {
    vector<vector<int>> image { {1,1,1}, {1,1,0}, {1,0,1} };
    auto result = Solution().floodFill(image, 1, 1, 2);
    for (const auto &r: result) {
        for (const auto &c: r) {
            std::cout << c << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
