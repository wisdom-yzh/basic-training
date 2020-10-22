#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = std::to_string(N);

        for (int i = static_cast<int>(s.size() - 1); i >= 1; i--) {
            if (s[i] < s[i - 1]) {
                s[i - 1]--;
                std::fill(s.begin() + i, s.end(), '9');
            }
        }

        return std::stoi(s);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);

        int ret = Solution().monotoneIncreasingDigits(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
