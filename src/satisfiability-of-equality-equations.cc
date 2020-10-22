#include <iostream>
#include <vector>
#include <string>
#include <array>
using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        std::array<int, 26> unionSet;
        for (int i = 0; i < 26; i++) {
            unionSet[i] = i;
        }

        for (const auto &equation: equations) {
            if (equation[1] == '=') {
                int a = equation[0];
                int b = equation[3];
                while (unionSet[a - 'a'] != a - 'a') {
                    a = unionSet[a - 'a'] + 'a';
                }
                while (unionSet[b - 'a'] != b - 'a') {
                    b = unionSet[b - 'a'] + 'a';
                }
                if (a > b) {
                    std::swap(a, b);
                }
                unionSet[b - 'a'] = unionSet[a - 'a'];
            }
        }

        for (const auto &equation: equations) {
            if (equation[1] == '!') {
                int a = equation[0];
                int b = equation[3];
                while (unionSet[a - 'a'] != a - 'a') {
                    a = unionSet[a - 'a'] + 'a';
                }
                while (unionSet[b - 'a'] != b - 'a') {
                    b = unionSet[b - 'a'] + 'a';
                }
                if (a == b) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    vector<vector<string>> testCases {
        {"a==b","b!=a"},
        {"b==a","a==b"},
        {"a==b","b==c","a==c"},
        {"a==b","b!=c","c==a"},
        {"c==c","b==d","x!=z"},
        {"b!=f","c!=e","f==f","d==f","b==f","a==f"},
    };

    for (auto &testCase: testCases) {
        cout << boolalpha << Solution().equationsPossible(testCase) << endl;
    }

    return 0;
}
