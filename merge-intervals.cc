#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        vector<Interval> result;

        std::sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
            return a.start < b.start;
        });

        result.push_back(intervals[0]);
        for (auto iter = intervals.begin() + 1; iter != intervals.end(); iter++) {
            auto front = result.end() - 1;
            auto next = iter;
            if (next->start <= front->end) {
                if (next->end > front->end) {
                    front->end = next->end;
                }
            } else {
                result.push_back(*next);
            }
        }

        return result;
    }
};

int main() {
    vector<Interval> input {
        { 1, 3 },
        { 2, 6 },
        { 8, 10 },
        { 15, 18 }
    };
    for (auto interval: Solution().merge(input)) {
        cout << interval.start << ',' << interval.end << endl;
    }

    return 0;
}
