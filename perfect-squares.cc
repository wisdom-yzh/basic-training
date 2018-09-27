#include <string>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> tempTable;
    vector<int> squareNumbers;

    int numSquares(int n) {
        squareNumbers.clear();
        tempTable.assign(n + 1, -1);
        for (int i = 1; ; i++) {
            int square = i * i;
            if (square <= n) {
                squareNumbers.push_back(square);
            }
            if (square >= n) {
                break;
            }
        }
        return this->recursionNumSquares(n);
    }

    int recursionNumSquares(int n) {
        if (tempTable[n] != -1) {
            return tempTable[n];
        }
        if (n == 0) {
            return 0;
        }
        int value = numeric_limits<int>::max();
        for (auto iter = squareNumbers.rbegin();
            iter != squareNumbers.rend();
            iter++) {
            int number = *iter;
            if (number <= n) {
                value = std::min(value, recursionNumSquares(n - number) + 1);
            }
        }
        
        tempTable[n] = value;
        return value;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().numSquares(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
