#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> count(26, 0);
        for (const auto &ch: letters) {
            count[ch - 'a']++;
        }

        int i = target - 'a';
        while (true) {
            i = (i + 1) % 26;
            if (count[i]) {
                return i + 'a';
            }
        }
    }
};

int main() {
    vector<char> letters {'c', 'f', 'j'};
    std::cout << Solution().nextGreatestLetter(letters, 'a');
    std::cout << Solution().nextGreatestLetter(letters, 'c');
    std::cout << Solution().nextGreatestLetter(letters, 'd');
    std::cout << Solution().nextGreatestLetter(letters, 'g');
    std::cout << Solution().nextGreatestLetter(letters, 'j');
    std::cout << Solution().nextGreatestLetter(letters, 'k');
    return 0;
}
