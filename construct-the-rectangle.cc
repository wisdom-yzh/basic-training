#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> result;
        int sqrtArea = static_cast<int>(std::sqrt(area));
        while ((area % sqrtArea) != 0) {
            sqrtArea--;
        }
        result.push_back(area / sqrtArea);
        result.push_back(sqrtArea);
        return result;
    }
};

int main() {
    for (auto &x: Solution().constructRectangle(4)) {
        cout << x << ',';
    }
    cout << endl;

    for (auto &x: Solution().constructRectangle(20)) {
        cout << x << ',';
    }
    cout << endl;

    return 0;
}
