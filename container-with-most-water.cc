#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;

class Solution {
private:

    int getArea(int x1, int y1, int x2, int y2) {
        return std::min(y1, y2) * (x2 - x1);
    }

public:

    int maxArea(vector<int>& height) {
        int result = 0;
        const unsigned int NUMBER = height.size();
        int i = 0, j = NUMBER - 1;

        while (i < j) {
            result = std::max(result, this->getArea(i, height[i], j, height[j]));
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
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
        vector<int> height = stringToIntegerVector(line);

        int ret = Solution().maxArea(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
