#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10) {
            return vector<string>(0);
        }
        map<char, int> mapTable {
            { 'A', 1 },
            { 'T', 2 },
            { 'C', 3 },
            { 'G', 4 }
        };
        set<uint64_t> nums;
        set<string> result;
        auto first = s.begin(), last = s.begin() + 9;
        uint64_t num = 0;
        int lowBase = 1, base = lowBase;
        for (auto i = last; i >= first; i--) {
            num += mapTable[*i] * base;
            base *= 5;
        }
        base /= 5;
        nums.insert(num);
        while (last != s.end()) {
            num -= mapTable[*first] * base;
            num *= 5;
            first++;
            last++;
            num += mapTable[*last];
            if (nums.find(num) != nums.end()) {
                result.insert(string(first, last + 1));
            } else {
                nums.insert(num);
            }
        }
        return vector<string>(result.begin(), result.end());
    }
};

int main() {
    string s("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for (auto &str: Solution().findRepeatedDnaSequences(s)) {
        cout << str << endl;
    }
    return 0;
}
