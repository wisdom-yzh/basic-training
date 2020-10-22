#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> current { 1 };
        vector<int> next { 1, 1 };

        if (rowIndex == 0) {
            return current;
        }
        if (rowIndex == 1) {
            return next;
        }
        for (int i = 2; i <= rowIndex; i++) {
            current = std::move(next);
            next.assign(1, 1);
            for (size_t i = 0; i < current.size() - 1; i++) {
                next.push_back(current[i] + current[i + 1]);
            }
            next.push_back(1);
        }
        return next;
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
        int rowIndex = stringToInteger(line);
        
        vector<int> ret = Solution().getRow(rowIndex);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
