#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int x = (tomatoSlices - 2 * cheeseSlices);
        if (x >= 0 && x % 2 == 0 && x / 2 <= cheeseSlices) {
            return vector<int>{ x / 2, cheeseSlices - x / 2 };
        }
        return vector<int>{};
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int tomatoSlices = stringToInteger(line);
        getline(cin, line);
        int cheeseSlices = stringToInteger(line);

        vector<int> ret = Solution().numOfBurgers(tomatoSlices, cheeseSlices);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
