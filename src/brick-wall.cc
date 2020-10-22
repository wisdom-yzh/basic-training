#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int maxBlank = 0;
        std::map<int, int> blanks;

        for (const auto & row: wall) {
            int position = 0;
            for (auto iter = row.begin(); iter != row.end() - 1; iter++) {
                position += *iter;
                auto p = blanks.find(position);
                if (p == blanks.end()) {
                    blanks.insert(std::make_pair(position, 1));
                    maxBlank = std::max(maxBlank, 1);
                } else {
                    p->second++;
                    maxBlank = std::max(maxBlank, p->second);
                }
            }
        }

        return wall.size() - maxBlank;
    }
};

int main() {
    vector<vector<vector<int>>> cases {
        {
            {1,2,2,1},
            {3,1,2},
            {1,3,2},
            {2,4},
            {3,1,2},
            {1,3,1,1}
        }
    };

    for (auto &m: cases) {
        std::cout << Solution().leastBricks(m) << std::endl;
    }
    return 0;
}
