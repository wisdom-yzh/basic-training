#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <iterator>
using namespace std;

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        map<int, int> regions;
        regions.insert({ 1, arr.size() });

        if (arr.size() == m) {
            return arr.size();
        }

        for (auto iter = arr.rbegin(); iter != arr.rend(); iter++) {
            int num = *iter;
            auto p = regions.lower_bound(num);
            if (p == regions.end() || p->first > num) {
                p = prev(p);
            }

            int l = p->first, r = p->second;
            regions.erase(p);

            if (l == r) {
                continue;
            }

            if (num - l == m || r - num == m)  {
                return arr.size() - 1 - distance(arr.rbegin(), iter);
            }

            if (l <= num - 1) {
                regions.insert({ l, num - 1 });
            }
            if (r >= num + 1) {
                regions.insert({ num + 1, r });
            }
        }

        return -1;
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
        vector<int> arr = stringToIntegerVector(line);
        getline(cin, line);
        int m = stringToInteger(line);

        int ret = Solution().findLatestStep(arr, m);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
