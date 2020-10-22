#include <iostream>
#include <vector>
#include <array>
#include <limits>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::array<int, 26> taskCount;
        taskCount.fill(0);

        int maxCount = 0, numOfMaxCount = 0;
        for (const auto &t: tasks) {
            taskCount[t - 'A']++;
            if (taskCount[t - 'A'] > maxCount) {
                maxCount = taskCount[t - 'A'];
                numOfMaxCount = 1;
            } else if (taskCount[t - 'A'] == maxCount) {
                numOfMaxCount++;
            }
        }

        return tasks.size() - maxCount > n * (maxCount - 1)
            ? tasks.size()
            : (n + 1) * (maxCount - 1) + numOfMaxCount;
    }
};

int main() {
    vector<char> tasks { 'A','A','A','B','B','B' };
    std::cout << Solution().leastInterval(tasks, 2) << std::endl;
    vector<char> tasks2 { 'A','A','A','A','A','A','B','C','D','E','F','G' };
    std::cout << Solution().leastInterval(tasks2, 2) << std::endl;
    return 0;
}
