#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        std::priority_queue<int,  std::vector<int>, std::greater<int>> q;

        for (int i = 0; i < heights.size() - 1; i++) {
            int gap = heights[i + 1] - heights[i];
            if (gap > 0) {
                q.push(gap);
            }

            if (q.size() > ladders) {
                const auto &minGap = q.top();
                if (minGap > bricks) {
                    return i;
                }
                bricks -= minGap;
                q.pop();
            }
        }

        return heights.size() - 1;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> heights = stringToIntegerVector(line);
        getline(cin, line);
        int bricks = stringToInteger(line);
        getline(cin, line);
        int ladders = stringToInteger(line);

        int ret = Solution().furthestBuilding(heights, bricks, ladders);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
