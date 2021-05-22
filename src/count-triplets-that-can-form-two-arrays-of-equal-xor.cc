#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            int num = arr[i];
            for (int k = i + 1; k < arr.size(); k++) {
                num ^= arr[k];
                if (num == 0) {
                    count += k - i;
                }
            }
        }

        return count;
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

        int ret = Solution().countTriplets(arr);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
