#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> result;

        string origin = S.substr(1, S.size() - 2);
        for (int comma = 1; comma < origin.size(); comma++) {
            vector<string> leftCombine;
            string left = origin.substr(0, comma);
            if (isValid(left)) {
                leftCombine.push_back(left);
            }
            for (int leftPoint = 1; leftPoint < left.size(); leftPoint++) {
                string leftNum = left.substr(0, leftPoint) + "." + left.substr(leftPoint);
                if (isValid(leftNum)) {
                    leftCombine.push_back(leftNum);
                }
            }

            if (leftCombine.empty()) {
                continue;
            }

            vector<string> rightCombine;
            string right = origin.substr(comma);
            if (isValid(right)) {
                rightCombine.push_back(right);
            }
            for (int rightPoint = 1; rightPoint < right.size(); rightPoint++) {
                string rightNum = right.substr(0, rightPoint) + "." + right.substr(rightPoint);
                if (isValid(rightNum)) {
                    rightCombine.push_back(rightNum);
                }
            }

            for (const auto &l: leftCombine) {
                for (const auto &r: rightCombine) {
                    result.push_back("(" + l + ", " + r + ")");
                }
            }
        }

        return result;
    }

    bool isValid(string &s) {
        bool pointFound = false;
        bool nextZeroWillReturnFalse = s[0] == '0';

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '.') {
                pointFound = true;
                if (nextZeroWillReturnFalse) {
                    nextZeroWillReturnFalse = false;
                }
            } else if (nextZeroWillReturnFalse) {
                return false;
            }
        }

        return !pointFound || (pointFound && s[s.size() - 1] != '0');
    }
};

int main() {
    Solution().ambiguousCoordinates("(00011)");
    Solution().ambiguousCoordinates("(123)");
    Solution().ambiguousCoordinates("(0123)");
    return 0;
}
