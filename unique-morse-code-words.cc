#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    static vector<string> code;

    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        for (const auto &word: words) {
            string w;
            for (const auto &ch: word) {
                w += Solution::code[ch - 'a'];
            }
            s.emplace(w);
        }

        return s.size();
    }
};

vector<string> Solution::code = {
    ".-",
	"-...",
	"-.-.",
	"-..",
	".",
	"..-.",
	"--.",
	"....",
	"..",
	".---",
	"-.-",
	".-..",
	"--",
	"-.",
	"---",
	".--.",
	"--.-",
	".-.",
	"...",
	"-",
	"..-",
	"...-",
	".--",
	"-..-",
	"-.--",
	"--.."
};

int main() {
    return 0;
}
