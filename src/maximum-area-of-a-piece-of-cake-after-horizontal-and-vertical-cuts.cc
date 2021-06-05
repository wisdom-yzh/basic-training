#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int maxH = 0, maxW = 0;

        std::sort(horizontalCuts.begin(), horizontalCuts.end());
        std::sort(verticalCuts.begin(), verticalCuts.end());

        for (int i = 0; i <= horizontalCuts.size(); i++) {
            if (i == 0) {
                maxH = std::max(maxH, horizontalCuts[i]);
            } else if (i == horizontalCuts.size()) {
                maxH = std::max(maxH, h - horizontalCuts[i - 1]);
            } else {
                maxH = std::max(maxH, horizontalCuts[i] - horizontalCuts[i - 1]);
            }
        }

        for (int i = 0; i <= verticalCuts.size(); i++) {
            if (i == 0) {
                maxW = std::max(maxW, verticalCuts[i]);
            } else if (i == verticalCuts.size()) {
                maxW = std::max(maxW, w - verticalCuts[i - 1]);
            } else {
                maxW = std::max(maxW, verticalCuts[i] - verticalCuts[i - 1]);
            }
        }

        return (static_cast<uint64_t>(maxH) * static_cast<uint64_t>(maxW)) % 1000000007;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

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
        int h = stringToInteger(line);
        getline(cin, line);
        int w = stringToInteger(line);
        getline(cin, line);
        vector<int> horizontalCuts = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> verticalCuts = stringToIntegerVector(line);

        int ret = Solution().maxArea(h, w, horizontalCuts, verticalCuts);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
