#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<double> mid {
            (p1[0] + p2[0] + p3[0] + p4[0]) / 4.0,
            (p1[1] + p2[1] + p3[1] + p4[1]) / 4.0
        };
        vector<vector<double>> vecs {
            { p1[0] - mid[0], p1[1] - mid[1] },
            { p2[0] - mid[0], p2[1] - mid[1] },
            { p3[0] - mid[0], p3[1] - mid[1] },
            { p4[0] - mid[0], p4[1] - mid[1] }
        };
        vector<double> lens {
            len(vecs[0]),
            len(vecs[1]),
            len(vecs[2]),
            len(vecs[3])
        };

        int vertical = 0, parallel = 0;
        for (int i = 1; i < 4; i++) {
            if (!equal(lens[0], lens[i])) {
                return false;
            }
            if (equal(vecs[0][0] * vecs[i][0] + vecs[0][1] * vecs[i][1], 0)) {
                vertical++;
            } else if (equal(vecs[0][0], -vecs[i][0]) &&
                    equal(vecs[0][1], -vecs[i][1])) {
                parallel++;
            }
        }

        return parallel == 1 && vertical == 2;
    }

    double len(vector<double> &vec) {
        return vec[0] * vec[0] + vec[1] * vec[1];
    }

    bool equal(double a, double b) {
        return std::abs(a - b) < 1e-4;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> p1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> p2 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> p3 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> p4 = stringToIntegerVector(line);

        bool ret = Solution().validSquare(p1, p2, p3, p4);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
