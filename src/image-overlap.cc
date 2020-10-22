#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<pair<int, int>> dA, dB;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                if (A[i][j] == 1) {
                    dA.push_back(make_pair(i, j));
                }
                if (B[i][j] == 1) {
                    dB.push_back(make_pair(i, j));
                }
            }
        }

        map<pair<int, int>, int> mat;
        for (const auto &pA: dA) {
            for (const auto &pB: dB) {
                mat[make_pair(pA.first - pB.first, pA.second - pB.second)]++;
            }
        }

        if (mat.empty()) {
            return 0;
        }

        using item_type = pair<pair<int, int>, int>;
        return std::max_element(mat.begin(), mat.end(), [](item_type &&a, item_type &&b) {
            return a.second < b.second;
        })->second;
    }
};

int main() {
    return 0;
}
