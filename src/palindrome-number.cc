#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int getIndexNumber(int x, int index) {
        return static_cast<int>(x / std::pow(10, index)) % 10;
    }

    int getMaxNumber(int x) {
        int result = 0;
        while (x > 0) {
            result++;
            x /= 10;
        }
        return result;
    }
    
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        const int MAX_NUMBER = this->getMaxNumber(x);
        for (int i = 0; i < MAX_NUMBER; i++) {
            if (this->getIndexNumber(x, i) !=
                this->getIndexNumber(x, MAX_NUMBER - i - 1)) {
                return false;
            }
        }

        return true;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
