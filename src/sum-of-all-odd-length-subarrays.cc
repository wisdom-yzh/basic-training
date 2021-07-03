#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int size = arr.size();
        int sum = 0;

        for (int i = 1; i <= size; i += 2) {
            for (int j = 0; j < arr.size() - i + 1; j++) {
                for (int k = 0; k < i; k++) {
                    sum += arr[j + k];
                }
            }
        }

        return sum;
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

        int ret = Solution().sumOddLengthSubarrays(arr);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
