#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) {
            return 0;
        }

        int parentK = (K + 1) / 2;
        int parent = kthGrammar(N - 1, parentK);
        return (parent == 0 && K == parentK * 2 - 1) ||
            (parent == 1 && K == parentK * 2) ? 0 : 1;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
            int N = stringToInteger(line);
            getline(cin, line);
            int K = stringToInteger(line);

            int ret = Solution().kthGrammar(N, K);

            string out = to_string(ret);
            cout << out << endl;
        }
    return 0;
}
