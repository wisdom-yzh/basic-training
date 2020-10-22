#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        uint64_t total = 0, totalCount = 0, maxCount = 0;
        double minValue = -1, maxValue = -1, maxCountValue;

        totalCount = count[0];
        if (count[0] != 0) {
            minValue = 0;
        }

        for (int i = 1; i < count.size(); i++) {
            if (count[i] != 0) {
                maxValue = i;
                if (minValue == -1) {
                    minValue = i;
                }
            }

            if (count[i] > maxCount) {
                maxCount = count[i];
                maxCountValue = static_cast<double>(i);
            }
            totalCount += count[i];
            total += i * count[i];
        }

        double median = getMedian(count, totalCount);
        double mean = static_cast<double>(total) / totalCount;

        return { minValue, maxValue, mean, median, maxCountValue };
    }

    double getMedian(vector<int> &count, int totalCount) {
        int mid = totalCount >> 1;
        int index = 0;

        for (int i = 0; i < count.size(); i++) {
            if (index + count[i] > mid) {
                return i;
            } else if (index + count[i] == mid) {
                if (totalCount % 2 != 0) {
                    return i;
                }
                for (int j = i + 1; j < count.size(); j++) {
                    if (count[j] != 0) {
                        return (i + j) / 2.0;
                    }
                }
            } else {
                index += count[i];
            }
        }

        return 0;
    }
};

int main() {
    vector<vector<int>> testCases {
        {0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,4,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };
    for (auto &testCase: testCases) {
        for (auto &num: Solution().sampleStats(testCase)) {
            cout << num << ' ';
        }
        cout << endl;
    }
    return 0;
}
