#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> current { 1 };
        vector<int> next { 1, 1 };
        vector<vector<int>> result;
        if (numRows == 0) {
            return result;
        }
        if (numRows == 1) {
            result.push_back(current);
            return result;
        }
        if (numRows == 2) {
            result.push_back(current);
            result.push_back(next);
            return result;
        }
        result.push_back(current);
        result.push_back(next);
        for (int i = 3; i <= numRows ; i++) {
            current = std::move(next);
            next.assign(1, 1);
            for (size_t i = 0; i < current.size() - 1; i++) {
                next.push_back(current[i] + current[i + 1]);
            }
            next.push_back(1);
            result.push_back(next);
        }
        return result;
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
        
        vector<vector<int>> ret = Solution().generate(rowIndex);
        
        for (auto &&row: ret) {
            string out = integerVectorToString(row);
            cout << out << endl;
        }
    }
    return 0;
}
