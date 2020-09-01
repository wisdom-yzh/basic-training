#include <vector>
#include <string>
#include <tuple>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> result;
        vector<string> arrStr;
        string str;
        std::istringstream iss(text);

        while (getline(iss, str, ' ')) {
            arrStr.push_back(str);
        }

        for (int i = 0; i < arrStr.size() - 2; i++) {
            if (arrStr[i] == first && arrStr[i + 1] == second) {
                result.push_back(arrStr[i + 2]);
            }
        }

        return result;
    }
};

int main() {
    vector<std::tuple<string, string, string>> testCases {
        { "alice is a good girl she is a good student", "a", "good" },
        { "we will we will rock you", "we", "will"},
    };
    for (const auto &testCase: testCases) {
        string text, first, second;
        std::tie(text, first, second) = testCase;
        for (const auto &str: Solution().findOcurrences(text, first, second)) {
            cout << str << ' ';
        }
        cout << endl;
    }
    return 0;
}
