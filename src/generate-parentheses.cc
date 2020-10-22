#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iterator>
using namespace std;

class Solution {
public:

    static const std::map<int, vector<string>> parenthesisTables;

    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return vector<string> {};
        }
        if (n == 1) {
            return vector<string> {
                "()"
            };
        }
        auto p = Solution::parenthesisTables.find(n);
        if (p != Solution::parenthesisTables.end()) {
            return p->second;
        }

        vector<string> result;
        for (int i = 1; i < n; i++) {
            vector<string> f0 = this->generateParenthesis(n - i);
            vector<string> f1 = this->generateParenthesis(i);
            for (auto j: f0) {
                for (auto k: f1) {
                    result.push_back(j + k);
                }
            }
        }
        for (auto j: this->generateParenthesis(n - 1)) {
            result.push_back("(" +  j + ")");
        }

        std::sort(result.begin(), result.end());
        auto newEnd = std::unique(result.begin(), result.end());
        return vector<string>(result.begin(), newEnd);
    }
};

const std::map<int, vector<string>> Solution::parenthesisTables;

int main () {
    Solution s;
    for (int i = 0; i < 7; i++) {
        auto v = s.generateParenthesis(i);
        cout << "n=" << i << "," << v.size() << endl;
        copy(v.begin(), v.end(), std::ostream_iterator<string>(cout, "\n"));
        cout << "\n";
    }
    return 0;
}
