#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        multiset<char> stringSet;
        for (auto &ch: s) {
            stringSet.emplace(ch);
        }
        for (auto &ch: t) {
            auto iter = stringSet.find(ch);
            if (iter == stringSet.end()) {
                return ch;
            } 
            stringSet.erase(iter);
        }
        return *stringSet.begin();
    }
};

int main() {
    cout << Solution().findTheDifference("abcd", "abcede");
    return 0;
}
