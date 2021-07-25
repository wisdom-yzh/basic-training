#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        uint32_t res = 0;
        uint32_t odd = 0, even = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] % 2 == 0) {
                even++;
            } else {
                int tmp = odd;
                odd = even + 1;
                even = tmp;
            }

            res = (res + odd) % MOD;
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
        vector<int> arr = stringToIntegerVector(line);

        int ret = Solution().numOfSubarrays(arr);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
