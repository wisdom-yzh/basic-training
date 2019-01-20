#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    static unordered_map<int64_t, int> cache;

    int integerReplacement(int64_t n) {

        if (n == 1) {
            return 0;
        }

        auto p = Solution::cache.find(n);

        if (p != Solution::cache.end()) {
            return p->second;
        }

        int result;

        if ((n & 1) == 0) {
            result = integerReplacement(n >> 1) + 1;
        } else {
            result = std::min(integerReplacement(n + 1), integerReplacement(n - 1)) + 1;
        }
        
        Solution::cache.emplace(n, result);
        return result;
    }
};

unordered_map<int64_t, int> Solution::cache;

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().integerReplacement(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
