#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int right = std::accumulate(weights.begin(), weights.end(), 0);
        int left = std::max(
            *std::max_element(weights.begin(), weights.end()),
            static_cast<int>(std::ceil(right/ D))
        );

        while (left < right) {
            int p = (left + right) / 2;
            int count = 0;
            int capacity = 0;

            for (int i = 0; i < weights.size(); i++) {
                if (capacity + weights[i] > p) {
                    capacity = weights[i];
                    count++;
                    if (count > D) {
                        break;
                    }
                } else {
                    capacity += weights[i];
                }
            }

            count++;

            if (count <= D) {
                right = p;
            } else {
                left = p + 1;
            }
        }

        return left;
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
        vector<int> weights = stringToIntegerVector(line);
        getline(cin, line);
        int D = stringToInteger(line);

        int ret = Solution().shipWithinDays(weights, D);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
