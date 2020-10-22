#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](int &a, int &b) {
            auto ab = to_string(a) + to_string(b);
            auto ba = to_string(b) + to_string(a);
            for (size_t i = 0; i < ab.size(); i++) {
                if (ab[i] > ba[i]) {
                    return true;
                } else if (ab[i] < ba[i]) {
                    return false;
                }
            }
            return false;
        });

        ostringstream oss;
        std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(oss));
        string result(oss.str());
        while (result.size() > 1 && result[0] == '0') {
            result.erase(0, 1);
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
        vector<int> nums = stringToIntegerVector(line);

        string ret = Solution().largestNumber(nums);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
