#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    static vector<int> moneyValue;

public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> money(3, 0);

        for (const auto &bill: bills) {
            if (!check(money, bill)) {
                return false;
            }
        }

        return true;
    }

    bool check(vector<int> &money, int bill) {
        int changeBack = bill - 5;
        int i = 2;

        while (changeBack != 0) {
            if (money[i] == 0 || moneyValue[i] > changeBack) {
                i--;
                if (i < 0) {
                    return false;
                }
            } else {
                changeBack -= moneyValue[i];
                money[i]--;
            }
        }
        money[bill == 5 ? 0 : bill == 10 ? 1 : 2]++;
        return true;
    }
};

vector<int> Solution::moneyValue { 5, 10, 20 };

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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> bills = stringToIntegerVector(line);

        bool ret = Solution().lemonadeChange(bills);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
