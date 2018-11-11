#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.empty()) {
            return 0;
        }
        unsigned int bits[words.size()];
        for (int i = 0; i < words.size(); i++) {
            unsigned int wordBits = 0;
            for (auto &ch: words[i]) {
                unsigned int bit = 1 << static_cast<unsigned int>(ch - 'a');
                if ((wordBits & bit) == 0) {
                    wordBits |= bit;
                }
            }
            bits[i] = wordBits;
        }

        int result = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if ((bits[i] & bits[j]) == 0) {
                    int tmp = words[i].size() * words[j].size();
                    result = max(result, tmp);
                }
            }
        }
        return result;
    }

};

int main() {
    vector<string> test { "abcw", "baz", "foo", "bar", "xtfn", "abcdef" };
    cout << Solution().maxProduct(test);
    return 0;
}
