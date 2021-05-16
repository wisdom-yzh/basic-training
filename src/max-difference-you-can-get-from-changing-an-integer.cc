#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        int minValue = num, maxValue = num;
        string s = std::to_string(num);

        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                string t = s;
                std::replace(t.begin(), t.end(), x + '0', y + '0');
                int n = stoi(t);
                if (t[0] == '0' || n == 0) {
                    continue;
                }
                maxValue = std::max(maxValue, n);
                minValue = std::min(minValue, n);
            }
        }

        return maxValue - minValue;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        int ret = Solution().maxDiff(num);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
