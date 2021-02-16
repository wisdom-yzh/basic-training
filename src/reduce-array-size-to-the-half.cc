#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> dict;
        for (auto num: arr) {
            dict[num]++;
        }

        priority_queue<int, vector<int>, less<int>> q;
        for (auto &p: dict) {
            q.push(p.second);
        }

        int x = 0;
        int size = (arr.size() + 0.5) / 2;
        while (size > 0 && !q.empty()) {
            size -= q.top();
            q.pop();
            x++;
        }

        return x;
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
        vector<int> arr = stringToIntegerVector(line);

        int ret = Solution().minSetSize(arr);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
