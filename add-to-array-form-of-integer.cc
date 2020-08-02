#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> kArr;
        while (K != 0) {
            kArr.push_back(K % 10);
            K /= 10;
        }
        std::reverse(A.begin(), A.end());

        vector<int> result;
        int i = 0, j = 0, acc = 0;

        while (i < A.size() || j < kArr.size()) {
            int num = acc;
            if (i < A.size()) {
                num += A[i];
                i++;
            }
            if (j < kArr.size()) {
                num += kArr[j];
                j++;
            }
            if (num >= 10) {
                num -= 10;
                acc = 1;
            } else {
                acc = 0;
            }
            result.push_back(num);
        }

        if (acc == 1) {
            result.push_back(1);
        }

        std::reverse(result.begin(), result.end());
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
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        int K = stringToInteger(line);

        vector<int> ret = Solution().addToArrayForm(A, K);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
