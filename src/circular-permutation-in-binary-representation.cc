#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> gray(grayCode(n));
        vector<int> res;

        auto iter = std::find(gray.begin(), gray.end(), start);
        std::copy(iter, gray.end(), std::back_inserter(res));
        std::copy(gray.begin(), iter, std::back_inserter(res));

        return res;
    }

    vector<int> grayCode(int n) {
        if (n == 0) {
            return vector<int>{0};
        } else if (n == 1) {
            return vector<int>{0, 1};
        } else {
            vector<int> result = this->grayCode(n - 1);
            int addOffset = 1 << (n - 1);
            for (int i = result.size() - 1; i >= 0; i--) {
                result.push_back(result[i] + addOffset);
            }
            return result;
        }
    }
};

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
        int n = stringToInteger(line);
        getline(cin, line);
        int start = stringToInteger(line);

        vector<int> ret = Solution().circularPermutation(n, start);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
