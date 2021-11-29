#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<bool> used(n + 1, false);
        vector<int> res(n * 2 - 1, 0);

        recursiveConstruct(res, 0, used, n);
        return res;
    }

    bool recursiveConstruct(vector<int> &arr, int index, vector<bool> &used, int n) {
        if (n == 0) {
            return true;
        }

        int next = 0;
        while (arr[index]) {
            next++;
            index++;
        }

        for (int i = used.size() - 1; i >= 1; i--) {
            if (!used[i]) {
                if (i == 1) {
                    arr[index] = i;
                    used[i] = true;
                    if (recursiveConstruct(arr, index + 1, used, n - 1)) {
                        return true;
                    }
                    arr[index] = 0;
                    used[i] = false;
                } else if (index + i < arr.size() && !arr[index + i]) {
                    arr[index] = arr[index + i] = i;
                    used[i] = true;
                    if (recursiveConstruct(arr, index + 1, used, n - 1)) {
                        return true;
                    }
                    arr[index] = arr[index + i] = 0;
                    used[i] = false;
                }
            }
        }

        index -= next;
        return false;
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

        vector<int> ret = Solution().constructDistancedSequence(n);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
