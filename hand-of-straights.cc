#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (W == 0 || (hand.size() % W) != 0) {
            return false;
        }

        std::map<int, int> cards;
        for (const auto &c: hand) {
            cards[c]++;
        }

        while (!cards.empty()) {
            auto iter = cards.begin();
            int index = iter->first;
            int value = iter->second;
            cards.erase(iter);

            for (int i = 1; i < W; i++) {
                iter = cards.find(index + i);
                if (iter == cards.end() || iter->second < value) {
                    return false;
                }
                if (iter->second == value) {
                    cards.erase(iter);
                } else {
                    iter->second -= value;
                }
            }
        }
        return true;
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
        vector<int> hand = stringToIntegerVector(line);
        getline(cin, line);
        int W = stringToInteger(line);

        bool ret = Solution().isNStraightHand(hand, W);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
