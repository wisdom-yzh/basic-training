#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        const int M = m;
        const int N = n;
        int paths[M][N];

        for (int i = 0; i < M; i++) {
            paths[i][0] = 1;
        }
        for (int j = 0; j < N; j++) {
            paths[0][j] = 1;
        }
        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
            }
        }

        return paths[M - 1][N - 1];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        int ret = Solution().uniquePaths(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
