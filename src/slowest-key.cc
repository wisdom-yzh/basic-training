#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char key = keysPressed[0];
        int time = releaseTimes[0];

        for (int i = 1; i < releaseTimes.size(); i++) {
            int t = releaseTimes[i] - releaseTimes[i - 1];
            if (t > time || t == time && keysPressed[i] > key) {
                time = t;
                key = keysPressed[i];
            }
        }

        return key;
    }
};

int main() {
    vector<pair<vector<int>, string>> testCases {
        { {9,29,49,50}, "cbcd" },
        { {12,23,36,46,62}, "spuda" }
    };
    for (auto [releaseTimes, keysPressed]: testCases) {
        cout << Solution().slowestKey(releaseTimes, keysPressed) << endl;
    }
    return 0;
}
