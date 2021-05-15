#include <vector>
#include <iostream>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size() - k;
        int sum = 0, partialSum = 0, minSum = std::numeric_limits<int>::max();

        for (int i = 0; i < cardPoints.size(); i++) {
            sum += cardPoints[i];
            if (i < n) {
                partialSum += cardPoints[i];
            }
        }

        minSum = partialSum;

        for (int i = 0; i < k; i++) {
            partialSum = partialSum - cardPoints[i] + cardPoints[i + n];
            minSum = std::min(partialSum, minSum);
        }

        return sum - minSum;
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
        vector<int> cardPoints = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);

        int ret = Solution().maxScore(cardPoints, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
