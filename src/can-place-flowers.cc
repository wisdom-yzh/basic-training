#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int maxPlacedFlowers = 0;
        int seriesZeroNum = 0;
        bool fromEdge = true;

        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                seriesZeroNum++;
            } else {
                if (fromEdge) {
                    maxPlacedFlowers += (seriesZeroNum >> 1);
                    fromEdge = false;
                } else {
                    maxPlacedFlowers += ((seriesZeroNum - 1) >> 1);
                }
                seriesZeroNum = 0;
            }
        }

        maxPlacedFlowers += fromEdge ? ((seriesZeroNum + 1) >> 1) : (seriesZeroNum >> 1);
        return maxPlacedFlowers >= n;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> flowerbed = stringToIntegerVector(line);
        getline(cin, line);
        int n = stringToInteger(line);

        bool ret = Solution().canPlaceFlowers(flowerbed, n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
