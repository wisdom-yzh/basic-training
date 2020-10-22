#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int clumsy(int N) {
        return recursionClumsy(N, 0, 0);
    }

    int recursionClumsy(int N, int num, int state) {
        if (N <= 0) {
            return num;
        }

        if (state == 0 || state == 2) {
            int next = N;
            if (N > 1) next *= (N - 1);
            if (N > 2) next /= (N - 2);
            return recursionClumsy(N - 3, num + (state == 0 ? next : -next), 1);
        }

        return recursionClumsy(N - 1, num + N, 2);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);

        int ret = Solution().clumsy(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
