#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if ((n % i) == 0) {
                cnt++;
            }
            if (cnt == k) {
                return i;
            }
        }
        return -1;
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

        int ret = Solution().kthFactor(n, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
