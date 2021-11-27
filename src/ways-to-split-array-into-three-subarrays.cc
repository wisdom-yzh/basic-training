#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();

        vector<int> psum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            psum[i + 1] = psum[i] + nums[i];
        }

        int res = 0;
        int a = 1, b = 1;
        for (int i = 0; i < n - 2; i++) {
            a = std::max(i + 1, a);
            while (a < n - 1 && psum[a + 1] - psum[i + 1] < psum[i + 1]) {
                a++;
            }
            if (a == n - 1) {
                break;
            }
            b = std::max(b, a);
            while (b < n - 1 && psum[n] - psum[b + 1] >= psum[b + 1] - psum[i + 1]) {
                b++;
            }
            res= (res + (b - a)) % 1000000007;
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
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().waysToSplit(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
