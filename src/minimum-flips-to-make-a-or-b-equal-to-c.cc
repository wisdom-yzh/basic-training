#include <iostream>
#include <string>
#include <bitset>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result = 0;
        std::bitset<32> setA(a), setB(b), setN(a | b), setC(c);
        for (int i = 0; i < 32; i++) {
            if (setN[i] != setC[i]) {
                if (setC[i] == 0) {
                    if (setA[i] == 1) {
                        result++;
                    }
                    if (setB[i] == 1) {
                        result++;
                    }
                } else {
                    result++;
                }
            }
        }
        return result;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int a = stringToInteger(line);
        getline(cin, line);
        int b = stringToInteger(line);
        getline(cin, line);
        int c = stringToInteger(line);

        int ret = Solution().minFlips(a, b, c);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
