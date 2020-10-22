#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int p = 0, q = (int)citations.size() - 1;
        int result = 0;
        int count = (int)citations.size();

        while (p <= q) {
            int mid = (p + q) / 2;
            int num = count - mid;
            if (num >= citations[mid]) {
                result = std::max(result, citations[mid]);
                p = mid + 1;
            } else {
                result = std::max(result, num);
                q = mid - 1;
            }
        }
        return result;
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
        vector<int> citations = stringToIntegerVector(line);

        int ret = Solution().hIndex(citations);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
