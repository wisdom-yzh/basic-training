#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        // newton iterator
        double current;
        double next = x;

        do {
            current = next;
            next = current / 2.0 + x / 2.0 / current;
        }
        while (static_cast<int>(next - current) != 0);
        
        return next;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().mySqrt(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
