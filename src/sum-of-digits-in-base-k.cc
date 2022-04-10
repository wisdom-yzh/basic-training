#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    int sumBase(int n, int k) {
        int res = 0;
        while (n > 0) {
            res += (n % k);
            n /= k;
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
        
        int ret = Solution().sumBase(n, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
