#include <iostream>
#include <algorithm>
#include <vector>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(std::vector<Interval>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        std::sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
            if (a.start != b.start) {
                return a.start <= b.start;
            }
            return a.end <= b.end;
        });

        std::vector<int> dp(intervals.size(), 1);

        for (int i = 1; i < intervals.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (intervals[i].start >= intervals[j].end) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        return static_cast<int>(intervals.size()) - *std::max_element(dp.begin(), dp.end());
    }
};

int main() {
    std::vector<Interval> intervals {
        {1,2}, {2,3}, {3,4}, {1,3}
    };
    std::cout << Solution().eraseOverlapIntervals(intervals);
    return 0;
}
