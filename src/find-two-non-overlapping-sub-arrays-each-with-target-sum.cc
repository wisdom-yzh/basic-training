#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    const int INF = 1e8 + 5;

    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size(), cnt = 0, ans = INF;
        vector<int> pre(n + 1, INF);
        for (int l = 0, r = 1; r <= n; ++r) {
            cnt += arr[r - 1];
            while (cnt > target) {
                cnt -= arr[l++];
            }
            if (cnt == target) {
                pre[r] = min(pre[r - 1], r - l);
                ans = min(ans, pre[l] + r - l);
            }
            else pre[r] = pre[r - 1];
        }
        return ans == INF ? -1 : ans;
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
        vector<int> arr = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        int ret = Solution().minSumOfLengths(arr, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
