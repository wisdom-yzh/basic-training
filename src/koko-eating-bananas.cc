#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int lo = 1, hi = pow(10, 9);
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (!possible(piles, H, mi)) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        return lo;
    }

    bool possible(vector<int>& piles, int H, int K) {
        int time = 0;
        for (int p: piles) {
            time += std::ceil(p / (double)K);
        }
        return time <= H;
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
        vector<int> piles = stringToIntegerVector(line);
        getline(cin, line);
        int H = stringToInteger(line);

        int ret = Solution().minEatingSpeed(piles, H);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
