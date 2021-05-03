#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <deque>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> result;
        std::deque<int> arr;
        for (int i = 1; i <= m; i++) {
            arr.push_back(i);
        }
        for (auto &q: queries) {
            auto el = std::find(arr.begin(), arr.end(), q);
            result.push_back(distance(arr.begin(), el));
            arr.erase(el);
            arr.push_front(q);
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

int stringToInteger(string input) {
    return stoi(input);
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
        vector<int> queries = stringToIntegerVector(line);
        getline(cin, line);
        int m = stringToInteger(line);

        vector<int> ret = Solution().processQueries(queries, m);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
