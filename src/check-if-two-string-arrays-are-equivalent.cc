#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return accumulate(word1.begin(), word1.end(), string("")) ==
               accumulate(word2.begin(), word2.end(), string(""));
    }
};

int main() {
    vector<pair<vector<string>, vector<string>>> testCases {
        {{"ab", "c"}, {"a", "bc"}},
        {{"a", "cb"}, {"ab", "c"}},
        {{"abc", "d", "defg"}, {"abcddefg"}},
    };
    for (auto &[word1, word2]: testCases) {
        cout << boolalpha << Solution().arrayStringsAreEqual(word1, word2) << endl;
    }
    return 0;
}
