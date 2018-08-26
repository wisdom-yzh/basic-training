#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while (n > 0) {
            if (n % 26 == 0) {
                s.push_back('Z');
                n /= 26;
                n--;
            } else {
                s.push_back((n % 26) + 'A' - 1);
                n /= 26;
            }
        }
        std::reverse(s.begin(), s.end());
        return s;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        string ret = Solution().convertToTitle(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
