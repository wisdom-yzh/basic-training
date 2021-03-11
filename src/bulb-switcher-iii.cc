#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int res = 0, maxIndex = 0, lightCount = 0;

        for (auto &index: light) {
            maxIndex = std::max(maxIndex, index);
            lightCount++;

            if (maxIndex == lightCount) {
                res++;
            }
        }

        return res;
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
        vector<int> light = stringToIntegerVector(line);

        int ret = Solution().numTimesAllBlue(light);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
