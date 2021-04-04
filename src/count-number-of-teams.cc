#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        for (int i = 1; i < rating.size() - 1; i++) {
            int incAfter = 0, decAfter = 0, incBefore = 0, decBefore = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (rating[j] < rating[i]) {
                    incBefore++;
                }
                if (rating[j] > rating[i]) {
                    decBefore++;
                }
            }
            for (int j = i + 1; j < rating.size(); j++) {
                if (rating[j] < rating[i]) {
                    decAfter++;
                }
                if (rating[j] > rating[i]) {
                    incAfter++;
                }
            }
            res += (incBefore * incAfter) + (decBefore * decAfter);
        }
        return res;
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
        vector<int> rating = stringToIntegerVector(line);
        int ret = Solution().numTeams(rating);
        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
