#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0, sum = 0;
        if (arr.size() < k) {
            return 0;
        }

        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        if (sum >= threshold * k) {
            res++;
        }
        for (int i = k; i < arr.size(); i++) {
            sum = sum + arr[i] - arr[i - k];
            res += sum >= threshold * k ? 1 : 0;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> arr = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        getline(cin, line);
        int threshold = stringToInteger(line);

        int ret = Solution().numOfSubarrays(arr, k, threshold);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
