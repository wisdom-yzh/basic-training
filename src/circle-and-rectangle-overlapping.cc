#include <vector>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if (x_center + radius < x1 || x_center - radius > x2 ||
            y_center + radius < y1 || y_center - radius > y2) {
            return false;
        }

        double s = sqrt(pow(x_center - (x2 + x1) / 2, 2) + pow(y_center - (y2 + y1) / 2, 2));
        double l = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) / 2 + radius;
        return s <= l;
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
        int radius = stringToInteger(line);
        getline(cin, line);
        int x_center = stringToInteger(line);
        getline(cin, line);
        int y_center = stringToInteger(line);
        getline(cin, line);
        int x1 = stringToInteger(line);
        getline(cin, line);
        int y1 = stringToInteger(line);
        getline(cin, line);
        int x2 = stringToInteger(line);
        getline(cin, line);
        int y2 = stringToInteger(line);

        bool ret = Solution().checkOverlap(radius, x_center, y_center, x1, y1, x2, y2);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
