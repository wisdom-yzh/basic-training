#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> result;
        for (int i = N == 1 ? 0 : 1; i <= 9; i++) {
            recursiveNumsSameConsecDiff(N, K, i, result);
        }
        return result;
    }

    void recursiveNumsSameConsecDiff(int N, int K, int current, vector<int> &result) {
        if (N == 1) {
            result.push_back(current);
            return;
        }
        int num = current % 10;
        if (num - K >= 0) {
            recursiveNumsSameConsecDiff(N - 1, K, 10 * current + num - K, result);
        }
        if (K != 0 && num + K < 10) {
            recursiveNumsSameConsecDiff(N - 1, K, 10 * current + num + K, result);
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
        int N = stringToInteger(line);
        getline(cin, line);
        int K = stringToInteger(line);

        vector<int> ret = Solution().numsSameConsecDiff(N, K);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
