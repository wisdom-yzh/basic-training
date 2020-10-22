#include <iostream>
using namespace std;

class Solution {
public:
    int binaryGap(int N) {
        int bit, distance = 0, maxDistance = 0;

        while (N != 0) {
            bit = N % 2;
            if (bit == 0) {
                if (distance > 0 ) {
                    distance++;
                }
            } else {
                maxDistance = std::max(distance, maxDistance);
                distance = 1;
            }

            N /= 2;
        }

        return maxDistance;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);

        int ret = Solution().binaryGap(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
