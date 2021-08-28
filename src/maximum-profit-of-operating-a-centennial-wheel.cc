#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <limits>
using namespace std;

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
       int waitingCount = 0;
       int profit = 0, index = 0;
       int maxProfit = std::numeric_limits<int>::min(), maxIndex = 0;

       for (auto &customer: customers) {
            waitingCount += customer;
            int remain = std::max(waitingCount - 4, 0);
            int up = waitingCount - remain;
            index++;

            profit += up * boardingCost;
            profit -= runningCost;
            if (profit > maxProfit) {
                maxProfit = profit;
                maxIndex = index;
            }
            waitingCount = remain;
       }

       while (waitingCount > 0) {
           int remain = std::max(waitingCount - 4, 0);
           int up = waitingCount - remain;
           index++;

           profit += up * boardingCost;
           profit -= runningCost;
           if (profit > maxProfit) {
               maxProfit = profit;
               maxIndex = index;
           }
           waitingCount = remain;
       }

       return maxProfit > 0 ? maxIndex : -1;
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
        vector<int> customers = stringToIntegerVector(line);
        getline(cin, line);
        int boardingCost = stringToInteger(line);
        getline(cin, line);
        int runningCost = stringToInteger(line);

        int ret = Solution().minOperationsMaxProfit(customers, boardingCost, runningCost);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
