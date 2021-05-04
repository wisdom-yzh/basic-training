#include <vector>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        if (k > 3 * pow(2, n - 1)) {
            return "";
        }
        string res;
        k--;
        for (int i = n; i >= 1; i--) {
            int c = pow(2, i - 1), temp= k / c;
            k %= c;

            if (i == n) {
                res.push_back('a' + temp);
            } else {
                if (res.back() == 'a') {
                    res.push_back(temp ? 'c' : 'b');
                } else if (res.back() == 'b') {
                    res.push_back(temp ? 'c' : 'a');
                } else if (res.back() == 'c') {
                    res.push_back(temp? 'b' : 'a');
                }
            }
        }
        return res;
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

        string ret = Solution().getHappyString(n, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
