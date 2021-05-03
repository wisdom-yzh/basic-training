#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        pair<int, char> arr[3] { {a, 'a'}, {b, 'b'}, {c, 'c'} };
        char p = '0', pp = '0';
        string res;

        while (true) {
            std::sort(arr, arr + 3, [](const pair<int, char> &a, const pair<int, char> &b) {
                return a.first < b.first;
            });

            pair<int, char> &x = arr[2].second == p && arr[2].second == pp ? arr[1] : arr[2];
            if (x.first == 0) {
                break;
            }

            res.push_back(x.second);
            x.first--;
            pp = p;
            p = x.second;
        }

        return res;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int a = stringToInteger(line);
        getline(cin, line);
        int b = stringToInteger(line);
        getline(cin, line);
        int c = stringToInteger(line);

        string ret = Solution().longestDiverseString(a, b, c);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
