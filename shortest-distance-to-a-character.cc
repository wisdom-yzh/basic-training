#include <vector>
#include <string>
#include <limits>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> result(S.size(), std::numeric_limits<int>::max());

        int pos = -1;
        while (true) {
            pos = S.find_first_of(C, pos + 1);

            if (pos == string::npos) {
                break;
            }

            for (int i = 0; i < result.size(); i++) {
                result[i] = std::min(result[i], std::abs(i - pos));
            }
        }

        return result;
    }
};

int main() {
    Solution().shortestToChar("loveleetcode", 'e');
    return 0;
}
