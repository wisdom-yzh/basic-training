#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> res {
            0,1,1,2,2,3,3,3,3,4,4,5,5,5,5,5,
            5,5,5,7,7,8,8,8,8,8,8,8,8,8,8,8,
            8,8,8,9,9,11,11,11,11,11,11,13,13,
            13,13,13,13,13,13,13,13,13,13,13,13,
            13,13,13,13,13,13,13,13,13,13,13,13,
            14,14,14,14,15,15,18,18,18,18,18,18,
            18,18,19,19,21,21,21,21,21,21,21,21,
            21,21,21,21,21,21,21,21
        };
        return res[n];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().getMaximumGenerated(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
