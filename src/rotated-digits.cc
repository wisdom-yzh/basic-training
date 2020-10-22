#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0;
        for (int i = 1; i <= N; i++) {
            if (good(i)) {
                count++;
            }
        }
        return count;
    }

    bool good(int x) {
        bool rotated = false;
        int y;

        while (x > 0) {
            y = x % 10;
            switch (y) {
                case 0:
                case 1:
                case 8:
                    break;
                case 2:
                case 5:
                case 6:
                case 9:
                    rotated = true;
                    break;
                default:
                    return false;
            }
            x /= 10;
        }
        return rotated;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
            int N = stringToInteger(line);

            int ret = Solution().rotatedDigits(N);

            string out = to_string(ret);
            cout << out << endl;
        }
    return 0;
}
