#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0, remainEmptyBottles = 0;

        while (numBottles > 0) {
            res += numBottles;
            remainEmptyBottles += numBottles % numExchange;
            numBottles /= numExchange;
            if (remainEmptyBottles >= numExchange) {
                numBottles += remainEmptyBottles / numExchange;
                remainEmptyBottles %= numExchange;
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
        int numBottles = stringToInteger(line);
        getline(cin, line);
        int numExchange = stringToInteger(line);

        int ret = Solution().numWaterBottles(numBottles, numExchange);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
