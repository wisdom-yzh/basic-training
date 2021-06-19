#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        int count = high - low + 1;
        if (count % 2 == 0 || low % 2 == 0) {
            return count / 2;
        }
        return count / 2 + 1;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int low = stringToInteger(line);
        getline(cin, line);
        int high = stringToInteger(line);

        int ret = Solution().countOdds(low, high);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
