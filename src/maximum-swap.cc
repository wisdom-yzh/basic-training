#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        vector<char> count(10);

        for (auto &ch: str) {
            count[ch - '0']++;
        }

        int startIndex = 0;
        for (int i = 9; i >= 0; i--) {
            while (count[i] > 0) {
                if (str[startIndex] - '0' == i) {
                    count[i]--;
                    startIndex++;
                } else {
                    return findMaxSwap(str, startIndex, i);
                }
            }
        }

        return num;
    }

    int findMaxSwap(string &str, int startIndex, int num) {
        int maxValue = -1;

        for (int i = startIndex + 1; i < str.size(); i++) {
            if (str[i] - '0' != num) {
                continue;
            }
            std::swap(str[i], str[startIndex]);
            maxValue = std::max(maxValue, std::stoi(str, 0, 10));
            std::swap(str[i], str[startIndex]);
        }

        return maxValue;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        int ret = Solution().maximumSwap(num);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
