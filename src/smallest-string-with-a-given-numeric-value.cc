#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n, 'a');

        k -= n;
        for (int i = n - 1; i >= 0 && k >= 0; i--) {
            if (k > 25) {
                s[i] = 'z';
                k -= 25;
            }
            else {
                s[i] = 'a' + k;
                k -= k;
            }
        }

        return s;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);

        string ret = Solution().getSmallestString(n, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
