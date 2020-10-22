#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        if (B == 0) return string(A, 'a');
        if (A == 0) return string(B, 'b');
        if (A==B) return "ab" + strWithout3a3b(A-1, B-1);
        return A > B ? "aab" + strWithout3a3b(A-2,B-1) : "bba" + strWithout3a3b(A-1, B-2);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int A = stringToInteger(line);
        getline(cin, line);
        int B = stringToInteger(line);

        string ret = Solution().strWithout3a3b(A, B);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
