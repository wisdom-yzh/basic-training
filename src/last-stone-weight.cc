#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> heap(stones.begin(), stones.end());

        while (heap.size() >= 2) {
            int y = heap.top();
            heap.pop();
            int x = heap.top();
            heap.pop();

            if (x != y) {
                heap.push(y - x);
            }
        }

        return heap.empty() ? 0 : heap.top();
    }
};

int main() {
    vector<vector<int>> testCases {
        {2,7,4,1,8,1}
    };
    for (auto &testCase: testCases) {
        cout << Solution().lastStoneWeight(testCase) << endl;
    }
    return 0;
}
