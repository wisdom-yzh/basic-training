#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        target = std::abs(target);
        int k = 0;
        while (target > 0) {
            target -= ++k;
        }
        return target % 2 == 0 ? k : k + 1 + k%2;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int target = stringToInteger(line);

        int ret = Solution().reachNumber(target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
