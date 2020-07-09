#include <iostream>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    const static set<string> str;

public:
    bool reorderedPowerOf2(int N) {
        string s = std::to_string(N);
        std::sort(s.begin(), s.end());
        return str.find(s) != str.end();
    }
};

const set<string> Solution::str = []() {
    set<string> v;
    int num = 1;
    for (int i = 0; i < 30; i++) {
        string s = std::to_string(num);
        std::sort(s.begin(), s.end());
        v.emplace(s);
        num <<= 1;
    }
    return v;
}();

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);

        bool ret = Solution().reorderedPowerOf2(N);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
