#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        std::map<int, int> s;

        for (int i = 1; i <= n; i++) {
            int sum = 0;
            int t = i;
            while (t != 0) {
                sum += t % 10;
                t /= 10;
            }
            s[sum]++;
        }

        int largest = 0, count = 0;
        for (auto &p: s) {
            if (p.second > largest) {
                count = 1;
                largest = p.second;
            } else if (p.second == largest) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    vector<int> testCases { 13, 2 };
    for (auto &testCase: testCases) {
        cout << Solution().countLargestGroup(testCase) << endl;
    }
    return 0;
}
