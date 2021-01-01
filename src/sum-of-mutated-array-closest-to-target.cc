#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        std::sort(arr.begin(), arr.end());
        int minValue = arr.front(), maxValue = arr.back(), size = arr.size();
        double average = static_cast<double>(target) / size;

        if (average < minValue) {
            return std::round(average);
        }

        if (average > maxValue) {
            return maxValue;
        }

        int index = arr.size() - 1;
        int sum = std::accumulate(arr.begin(), arr.end(), 0);
        int delta = std::numeric_limits<int>::max();
        for (int value = maxValue; value >= minValue; value--, sum -= arr.size() - 1 - index) {
            while (value < arr[index]) {
                sum -= arr[index] - value;
                index--;
            }
            int newDelta = std::abs(sum - target);
            if (delta >= newDelta) {
                delta = newDelta;
            } else {
                return value + 1;
            }
        }

        return minValue;
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

        int ret = Solution().findBestValue(arr, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
