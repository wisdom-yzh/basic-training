#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int, vector<int>> dict;
        for (auto &num: arr) {
            dict[getNumberOfOne(num)].push_back(num);
        }

        vector<int> result;
        for (auto &p: dict) {
            std::sort(p.second.begin(), p.second.end());
            std::copy(p.second.begin(), p.second.end(), std::back_inserter(result));
        }
        return result;
    }

    int getNumberOfOne(int num) {
        int count = 0;
        while (num != 0) {
            num &= (num - 1);
            count++;
        }
        return count;
    }
};

int main() {
    vector<vector<int>> testCases {
        {0,1,2,3,4,5,6,7,8},
        {1024,512,256,128,64,32,16,8,4,2,1},
        {10000,10000},
        {2,3,5,7,11,13,17,19},
    };
    for (auto &testCase: testCases) {
        for (auto &x: Solution().sortByBits(testCase)) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
