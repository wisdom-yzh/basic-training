#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        std::unordered_set<int> s;
        for (auto &num: arr) {
            if (s.find(num) != s.end()) {
                return true;
            }
            if (num % 2 == 0) {
                s.emplace(num / 2);
            }
            s.emplace(num * 2);
        }
        return false;
    }
};

int main() {
    vector<vector<int>> testCases {
        { 10,2,5,3 },
        { 7,1,14,11 },
        { 3,1,7,11 }
    };
    for (auto &arr: testCases) {
        cout << boolalpha << Solution().checkIfExist(arr) << endl;
    }
    return 0;
}
