#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));
        return dp(table, 1, n);
    }

    int dp(vector<vector<int>> &table, int p, int q) {
        if (p >= q) {
            return 0;
        }
        if (table[p][q] != 0) {
            return table[p][q];
        }
        int ret = std::numeric_limits<int>::max();
        for (int i = p; i <= q; i++) {
            ret = std::min(ret, i + std::max(dp(table, p, i - 1), dp(table, i + 1, q)));
        }
        table[p][q] = ret;
        return ret;
    }
};


int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().getMoneyAmount(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
