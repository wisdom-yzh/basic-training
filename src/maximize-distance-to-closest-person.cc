#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        if (seats.empty()) {
            return 0;
        }
        int p = -1, maxDist = 1;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] != 0) {
                if (p == -1) {
                    maxDist = std::max(maxDist, i);
                } else  {
                    maxDist = std::max(maxDist, (i - p) / 2);
                }
                p = i;
            } else if (i == seats.size() - 1) {
                maxDist = std::max(maxDist, i - p);
            }
        }
        return maxDist;
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
        vector<int> seats = stringToIntegerVector(line);

        int ret = Solution().maxDistToClosest(seats);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
