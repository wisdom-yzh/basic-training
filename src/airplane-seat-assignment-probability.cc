#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n == 1 ? 1 : 0.5;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        double ret = Solution().nthPersonGetsNthSeat(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
