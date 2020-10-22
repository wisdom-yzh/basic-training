#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        std::map<int, int> groups;
        for (const auto &num: deck) {
            groups[num]++;
        }
        int result = -1;
        for (const auto &g: groups) {
           if (result == -1) {
               result = g.second;
           } else {
               result = gcd(result, g.second);
               if (result == 1) {
                   return false;
               }
           }
        }

        return result != 1;
    }

    int gcd(int a, int b) {
        if (a < b) {
            std::swap(a, b);
        }
        if (a % b == 0) {
            return b;
        }
        return gcd(b, a % b);
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> deck = stringToIntegerVector(line);

        bool ret = Solution().hasGroupsSizeX(deck);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
