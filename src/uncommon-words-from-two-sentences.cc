#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        map<string, int> dictA, dictB;
        vector<string> result;

        istringstream sA(A), sB(B);
        string str;

        while (getline(sA, str, ' ')) {
            dictA[str]++;
        }

        while (getline(sB, str, ' ')) {
            dictB[str]++;
        }

        for (const auto &pair: dictA) {
            if (pair.second == 1 && dictB[pair.first] == 0) {
                result.push_back(pair.first);
            }
        }

        for (const auto &pair: dictB) {
            if (pair.second == 1 && dictA[pair.first] == 0) {
                result.push_back(pair.first);
            }
        }

        return result;
    }
};

int main() {

    return 0;
}
