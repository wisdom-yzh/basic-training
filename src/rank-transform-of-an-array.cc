#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        std::priority_queue<int, vector<int>, std::greater_equal<int>> q;
        std::multimap<int, int> indexDict;

        for (int i = 0; i < arr.size(); i++) {
            q.push(arr[i]);
            indexDict.emplace(arr[i], i);
        }

        int rank = 0, num = -1;
        while (!q.empty()) {
            if (q.top() != num) {
                rank++;
                num = q.top();
            }
            auto iter = indexDict.find(num);
            arr[iter->second] = rank;
            indexDict.erase(iter);
            q.pop();
        }

        return arr;
    }
};

int main() {
    vector<vector<int>> testCases {
        { 40,10,20,30 },
        { 100,100,100 },
        { 37,12,28,9,100,56,80,5,12 }
    };
    for (auto &testCase: testCases) {
        for (auto &x: Solution().arrayRankTransform(testCase)) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
