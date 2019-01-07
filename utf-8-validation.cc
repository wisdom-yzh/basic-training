#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        return this->validUtf8(data, 0);
    }

    bool validUtf8(vector<int>& data, size_t index) {
        if (index == data.size()) {
            return true;
        }
        if ((data[index] >> 7) == 0) {
            return validUtf8(data, index + 1);
        }
        if (index == data.size() - 1) {
            return false;
        }
        if ((data[index] >> 5) == 0b110 &&
            (data[index + 1] >> 6 == 0b10)) {
            return validUtf8(data, index + 2);
        }
        if (index == data.size() - 2) {
            return false;
        }
        if ((data[index] >> 4) == 0b1110 &&
            (data[index + 1] >> 6 == 0b10) &&
            (data[index + 2] >> 6 == 0b10)) {
            return validUtf8(data, index + 3);
        }
        if (index == data.size() - 3) {
            return false;
        }
        if ((data[index] >> 3) == 0b11110 &&
            (data[index + 1] >> 6 == 0b10) &&
            (data[index + 2] >> 6 == 0b10) &&
            (data[index + 3] >> 6 == 0b10)) {
            return validUtf8(data, index + 4);
        }
        return false;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> data = stringToIntegerVector(line);

        bool ret = Solution().validUtf8(data);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
