#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z > x + y) {
            return false;
        }
        if (z == 0 || z == x || z == y || z == x + y || z == abs(x - y)) {
            return true;
        }

        std::queue<int> q;
        std::set<int> s;
        q.push(0);
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            if (top + x < x + y && s.find(top + x) == s.end()) {
                q.push(top + x);
                s.emplace(top + x);
            }
            if (top + y < x + y && s.find(top + y) == s.end()) {
                q.push(top + y);
                s.emplace(top + y);
            }
            if (y - top > 0 && s.find(y - top) == s.end()) {
                q.push(y - top);
                s.emplace(y - top);
            }
            if (x - top > 0 && s.find(x - top) == s.end()) {
                q.push(x - top);
                s.emplace(x - top);
            }
            if (s.find(z) != s.end()) {
                return true;
            }
        }
        return false;
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
        getline(cin, line);
        int y = stringToInteger(line);
        getline(cin, line);
        int z = stringToInteger(line);

        bool ret = Solution().canMeasureWater(x, y, z);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
