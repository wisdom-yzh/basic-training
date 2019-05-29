#include <unordered_set>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        static unordered_set<int> n = {6, 28, 496, 8128, 33550336};
        return n.count(num);
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
        int num = stringToInteger(line);

        bool ret = Solution().checkPerfectNumber(num);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
