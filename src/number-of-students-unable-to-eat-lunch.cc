#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        for (auto &s: sandwiches) {
            auto iter = std::find(students.begin(), students.end(), s);
            if (iter == students.end()) {
                break;
            }
            students.erase(iter);
        }
        return students.size();
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> students = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> sandwiches = stringToIntegerVector(line);

        int ret = Solution().countStudents(students, sandwiches);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
