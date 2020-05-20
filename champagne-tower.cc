#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> arr(query_glass + 1, vector<double>(query_row + 1, -1));
        arr[0][0] = poured;

        return std::min(dp(query_glass, query_row, arr), 1.0);
    }

    double dp(int x, int y, vector<vector<double>> &arr) {
        if (arr[x][y] != -1) {
            return arr[x][y];
        }

        arr[x][y] = 0;
        if (x > 0) {
            arr[x][y] += std::max(0.0, dp(x - 1, y - 1, arr) - 1) / 2.0;
        }
        if (x != y) {
            arr[x][y] += std::max(0.0, dp(x, y - 1, arr) - 1) / 2.0;
        }

        return arr[x][y];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int poured = stringToInteger(line);
        getline(cin, line);
        int query_row = stringToInteger(line);
        getline(cin, line);
        int query_glass = stringToInteger(line);

        double ret = Solution().champagneTower(poured, query_row, query_glass);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
