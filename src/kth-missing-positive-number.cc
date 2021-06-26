#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int res = 1;
        int idx = 0;
        for (int i = 0; i < k; ) {
            if (idx < arr.size() && res == arr[idx]) {
                idx++;
            } else {
                i++;
            }
            res++;
        }
        return res - 1;
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
        int k = stringToInteger(line);

        int ret = Solution().findKthPositive(arr, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
