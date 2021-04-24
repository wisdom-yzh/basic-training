#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int min = *std::min_element(salary.begin(), salary.end());
        int max = *std::max_element(salary.begin(), salary.end());

        return (std::accumulate(salary.begin(), salary.end(), 0) - min - max) /
            (salary.size() - 2.0);
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
        vector<int> salary = stringToIntegerVector(line);

        double ret = Solution().average(salary);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
