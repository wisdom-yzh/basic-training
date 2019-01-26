#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        std::priority_queue<int, vector<int>, std::less<int>> q(nums.begin(), nums.end());
        if (q.size() < 3) {
            return q.top();
        }
        int max = q.top();
        int top = q.top();
        while (q.top() == top) {
            q.pop();
            if (q.empty()) {
                return max;
            }
        }
        top = q.top();
        while (q.top() == top) {
            q.pop();
            if (q.empty()) {
                return max;
            }
        }
        return q.top();
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
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().thirdMax(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
