#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> alphabetLogs;
        vector<string> numberLogs;

        for (const auto &log: logs) {
            int index = log.find(' ');
            if (log[index + 1] >= '0' && log[index + 1] <= '9') {
                numberLogs.push_back(log);
            } else {
                alphabetLogs.push_back(log);
            }
        }

        std::sort(alphabetLogs.begin(), alphabetLogs.end(), [](string &log1, string &log2) {
            int index1 = log1.find(' ');
            int index2 = log2.find(' ');
            string s1 = log1.substr(index1);
            string s2 = log2.substr(index2);
            if (s1 == s2) {
                return log1.substr(0, index1) < log2.substr(0, index2);
            }
            return s1 < s2;
        });

        std::copy(numberLogs.begin(), numberLogs.end(), std::back_inserter(alphabetLogs));
        return alphabetLogs;
    }
};

int main() {
    vector<string> logs {
        "a1 9 2 3 1",
        "g1 act car",
        "zo4 4 7",
        "ab1 off key dog",
        "a8 act zoo"
    };
    vector<string> result = Solution().reorderLogFiles(logs);
    for (const auto &s: result) {
        cout << s << endl;
    }
    return 0;
}
