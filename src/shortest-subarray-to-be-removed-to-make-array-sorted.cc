#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int i = 0, j = arr.size() - 1;
        while (i < j && arr[i] <= arr[i + 1]) {
            i++;
        }
        while (j > i && arr[j] >= arr[j - 1]) {
            j--;
        }
        if (i == j) {
            return 0;
        }
        return dfs(arr, i, j);
    }

    int dfs(vector<int> &arr, int i, int j) {
        if (i < 0 || j >= arr.size() || arr[i] <= arr[j]) {
            return j - i - 1;
        }
        return std::min(dfs(arr, i - 1, j), dfs(arr, i, j + 1));
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

        int ret = Solution().findLengthOfShortestSubarray(arr);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
