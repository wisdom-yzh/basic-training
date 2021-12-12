#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int a = 0;

        for (int i = 1; i<= encoded.size() + 1; i++) {
            a^=i;
        }

        for (int i = encoded.size() - 1; i >= 0; i -= 2) {
            a ^= encoded[i];
        }

        vector<int> ans(encoded.size() + 1);
        ans[0] = a;

        for (int i = 0; i < encoded.size(); i++) {
            ans[i + 1] = ans[i] ^ encoded[i];
        }
        return ans;
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
        vector<int> encoded = stringToIntegerVector(line);

        vector<int> ret = Solution().decode(encoded);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
