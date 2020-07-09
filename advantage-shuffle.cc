#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        std::multimap<int, int> dictA;
        for (int i = 0; i < A.size(); i++) {
            dictA.insert({ A[i], i });
        }

        for (int i = 0; i < B.size(); i++) {
            int numB = B[i];
            auto iter = dictA.upper_bound(numB);
            if (iter == dictA.end()) {
                iter = dictA.begin();
            }

            A[i] = iter->first;
            dictA.erase(iter);
        }

        return A;
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
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> B = stringToIntegerVector(line);

        vector<int> ret = Solution().advantageCount(A, B);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
