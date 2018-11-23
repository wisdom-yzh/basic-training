#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> count(num + 1, 0);
        if (num >= 1) {
            count[1] = 1;
        }
        int step = 0;
        for (int i = 2; i <= num; i++) {
            if ((i & (i - 1)) == 0) {
                step = i;
                count[i] = 1;
            } else {
                count[i] = count[i - step] + 1;
            }
        }
        return count;
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
        int num = stringToInteger(line);
        
        vector<int> ret = Solution().countBits(num);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
