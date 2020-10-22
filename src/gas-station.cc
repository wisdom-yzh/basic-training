#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = std::accumulate(gas.begin(), gas.end(), 0);
        int totalCost = std::accumulate(cost.begin(), cost.end(), 0);
        if (totalCost > totalGas) {
            return -1;
        }

        int index = 0, currentGas = 0;
        for (size_t i = 0; i < gas.size(); i++) {
            currentGas += (gas[i] - cost[i]);
            if (currentGas < 0) {
                index = i + 1;
                currentGas = 0;
            }
        }
        return index;
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
        vector<int> gas = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> cost = stringToIntegerVector(line);

        int ret = Solution().canCompleteCircuit(gas, cost);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
