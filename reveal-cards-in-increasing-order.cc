#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        std::sort(deck.begin(), deck.end());
        std::deque<int> dest(deck.begin(), deck.end());
        std::deque<int> origin;

        while (!dest.empty()) {
            if (!origin.empty()) {
                origin.push_back(origin.front());
                origin.pop_front();
            }
            origin.push_back(dest.back());
            dest.pop_back();
        }

        return vector<int>(origin.rbegin(), origin.rend());
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> deck = stringToIntegerVector(line);

        vector<int> ret = Solution().deckRevealedIncreasing(deck);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
