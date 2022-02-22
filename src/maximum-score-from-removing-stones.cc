#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        if (a + b < c) {
            return a + b;
        }
        if (a + c < b) {
            return a + c;
        }
        if (b + c < a) {
            return b + c;
        }
        return (a + b + c) / 2;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int a = stringToInteger(line);
        getline(cin, line);
        int b = stringToInteger(line);
        getline(cin, line);
        int c = stringToInteger(line);

        int ret = Solution().maximumScore(a, b, c);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
