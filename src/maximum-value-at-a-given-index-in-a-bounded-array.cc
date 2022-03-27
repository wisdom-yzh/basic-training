#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int res = 1, l = index, r = index, sum = n;
        while (sum <= maxSum) {
            sum += r - l + 1;
            res++;
            l = l == 0 ? 0 : l - 1;
            r = r == n - 1 ? n - 1 : r + 1;
            if (l == 0 && r == n-1 && n < maxSum - sum ) {
                return res + (maxSum - sum) / n;
            }
        }
        return res - 1;
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
        int index = stringToInteger(line);
        getline(cin, line);
        int maxSum = stringToInteger(line);
        
        int ret = Solution().maxValue(n, index, maxSum);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
