#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> printVertically(string &s) {
        vector<string> mat;
        std::string word;
        std::istringstream iss(s);

        size_t longest = 0;
        while (std::getline(iss, word, ' ')) {
            mat.push_back(word);
            longest = std::max(word.size(), longest);
        }

        vector<string> result;
        for (int i = 0; i < longest; i++) {
            string s;
            for (int j = 0; j < mat.size(); j++) {
                s.push_back(mat[j].size() > i ? mat[j][i] : ' ');
            }
            s.erase(s.find_last_not_of(" ") + 1);
            result.push_back(s);
        }

        return result;
    }
};

int main() {
    vector<string> testCases {
        "HOW ARE YOU",
        "TO BE OR NOT TO BE",
        "CONTEST IS COMING"
    };
    for (auto &s: testCases) {
        for (auto &x: Solution().printVertically(s)) {
            cout << x << endl;
        }
        cout << endl;
    }
    return 0;
}
