#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if (k >= arr.size()) {
            return *std::max_element(arr.begin(), arr.end());
        }

        int x = arr[0];
        int cnt = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < x) {
                cnt++;
            } else {
                x = arr[i];
                cnt = 1;
            }

            if (cnt == k) {
                break;
            }
        }

        return x;
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

        int ret = Solution().getWinner(arr, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
