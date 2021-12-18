#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> sum(50, 0);
        int res = -1;

        for (int i = lowLimit; i <= highLimit; i++) {
            int x =i, s = 0;
            while (x) {
                s += x % 10;
                x /= 10;
            }
            sum[s]++;
            res = max(res, sum[s]);
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
        int lowLimit = stringToInteger(line);
        getline(cin, line);
        int highLimit = stringToInteger(line);

        int ret = Solution().countBalls(lowLimit, highLimit);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
