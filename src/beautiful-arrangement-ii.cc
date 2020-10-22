#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> vec(n);
        for (int i = 1; i <= n - k; i++) {
            vec[i - 1] = i;
        }

        bool flip = true;
        int left = n - k + 1, right = n;
        for (int i = n - k + 1; i <= n; i++) {
            if (flip) {
                vec[i - 1] = right--;
            } else {
                vec[i - 1] = left++;
            }
            flip = !flip;
        }

        return vec;
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
        int k = stringToInteger(line);

        vector<int> ret = Solution().constructArray(n, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
