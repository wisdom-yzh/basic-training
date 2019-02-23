#include <iostream>
#include <vector>
#include <map>
using namespace std;

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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        std::map<int, int> intervalMap;

        for (int i = 0; i < intervals.size(); ++i) {
            intervalMap.emplace(intervals[i].start, i);
        }

        vector<int> result;
        for (int i = 0; i < intervals.size(); i++) {
            auto iter = intervalMap.lower_bound(intervals[i].end);
            if (iter == intervalMap.end()) {
                result.push_back(-1);
            } else {
                result.push_back(iter->second);
            }
        }

        return result;
    }
};

int main() {
    vector<Interval> intervals {
        { 3, 4 }, { 2, 3 }, { 1, 2 }
    };
    for (auto &c: Solution().findRightInterval(intervals)) {
        std::cout << c << ' ';
    }
    return 0;
}
