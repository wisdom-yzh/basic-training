#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result(arr1.size());
        map<int, int> dict;
        for (auto &num: arr1) {
            dict[num]++;
        }

        int index = 0;
        for (auto &num: arr2) {
            auto iter = dict.find(num);
            for (int i = 0; i < iter->second; i++) {
                result[index++] = num;
            }
            dict.erase(iter);
        }

        for (auto &p: dict) {
            for (int i = 0; i < p.second; i++) {
                result[index++] = p.first;
            }
        }

        return result;
    }
};

int main() {
    vector<pair<vector<int>, vector<int>>> testCases {
        {{2,3,1,3,2,4,6,7,9,2,19}, {2,1,4,3,9,6}}
    };
    for (auto &testCase: testCases) {
        for (auto &num: Solution().relativeSortArray(testCase.first, testCase.second)) {
            cout << num << ' ';
        }
        cout << endl;
    }
    return 0;
}
