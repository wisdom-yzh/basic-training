#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats = 0;
        std::sort(people.begin(), people.end(), std::greater<int>());

        int p = 0, q = people.size() - 1;
        while (p <= q) {
            if (p < q && people[p] + people[q] <= limit) {
                p++;
                q--;
                boats++;
            } else {
                p++;
                boats++;
            }
        }

        return boats;
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
        vector<int> people = stringToIntegerVector(line);
        getline(cin, line);
        int limit = stringToInteger(line);

        int ret = Solution().numRescueBoats(people, limit);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
