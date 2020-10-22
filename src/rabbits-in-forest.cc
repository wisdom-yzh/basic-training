#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <array>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        std::array<int, 1000> count {};

        for (const auto &ans: answers) {
            count[ans]++;
        }

        int result = 0;
        for (int i = 0; i < 1000; i++) {
            result += (count[i] / (i + 1)) * (i + 1);
            if ((count[i] % (i + 1)) != 0) {
                result += (i + 1);
            }
        }

        return result;
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
        vector<int> answers = stringToIntegerVector(line);

        int ret = Solution().numRabbits(answers);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
