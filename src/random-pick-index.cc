#include <vector>
#include <unordered_map>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        srand(time(0));
        for (int i = 0; i < nums.size(); i++) {
            auto p = indexMap.find(nums[i]);
            if (p == indexMap.end()) {
                indexMap.emplace(nums[i], vector<int> { i });
            } else {
                indexMap[nums[i]].push_back(i);
            }
        }
    }
    
    int pick(int target) {
        auto p = indexMap.find(target);
        int size = p->second.size();
        return p->second[rand() % size];
    }
private:
    unordered_map<int, vector<int>> indexMap;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
int main() {
    Solution solution(vector<int> { 1, 2, 3, 3, 3 });
    cout << solution.pick(3) << endl;
    cout << solution.pick(1) << endl;
    return 0;
}
