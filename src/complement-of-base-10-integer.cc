#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) {
            return 1;
        }

        uint32_t i = 0, o = ~N;
        while (N > 0) {
            N >>= 1;
            i = (i << 1) + 1;
        }
        return i & o;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);

        int ret = Solution().bitwiseComplement(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
