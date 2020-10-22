#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static vector<pair<int, int>> direction;

    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (!matrix.size()) {
            return vector<pair<int, int>> {};
        }
        set<pair<int, int>> pacific;
        set<pair<int, int>> atlantic;

        getPacific(matrix, pacific);
        getAtlantic(matrix, atlantic);
        for (auto &p: pacific) {
            cout << "[" << p.first << "," << p.second << "]";
        }
        cout << endl;
        for (auto &p: atlantic) {
            cout << "[" << p.first << "," << p.second << "]";
        }
        cout << endl;

        vector<pair<int, int>> result;
        for (auto i = pacific.begin(); i != pacific.end(); i++) {
            auto coordinate = *i;
            if (atlantic.find(coordinate) != atlantic.end()) {
                result.push_back(*i);
            }
        }

        return result;
    }

    void getPacific(vector<vector<int>> &matrix, set<pair<int, int>> &pacific) {
        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        for (size_t i = 0; i < matrix.size(); i++) {
            auto p = make_pair(i, 0);
            q.push(p);
            visited.emplace(p);
            pacific.emplace(p);
        }
        for (size_t i = 0; i < matrix[0].size(); i++) {
            auto p = make_pair(0, i);
            q.push(p);
            visited.emplace(p);
            pacific.emplace(p);
        }

        while (!q.empty()) {
            auto p = q.front();
            for (auto &dp: Solution::direction) {
                auto np = make_pair(p.first + dp.first, p.second + dp.second);
                if (np.first >= 0 && np.first < matrix.size() &&
                    np.second >= 0 && np.second < matrix[0].size() &&
                    visited.find(np) == visited.end()) {
                    if (matrix[np.first][np.second] >= matrix[p.first][p.second]) {
                        q.push(np);
                        pacific.emplace(np);
                    }
                }
            }
            visited.emplace(p);
            q.pop();
        }
    }

    void getAtlantic(vector<vector<int>> &matrix, set<pair<int, int>> &atlantic) {
        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        for (size_t i = 0; i < matrix.size(); i++) {
            auto p = make_pair(i, matrix[0].size() - 1);
            q.push(p);
            visited.emplace(p);
            atlantic.emplace(p);
        }
        for (size_t i = 0; i < matrix[0].size(); i++) {
            auto p = make_pair(matrix.size() - 1, i);
            q.push(p);
            visited.emplace(p);
            atlantic.emplace(p);
        }

        while (!q.empty()) {
            auto p = q.front();
            for (auto &dp: Solution::direction) {
                auto np = make_pair(p.first + dp.first, p.second + dp.second);
                if (np.first >= 0 && np.first < matrix.size() &&
                    np.second >= 0 && np.second < matrix[0].size() &&
                    visited.find(np) == visited.end()) {
                    if (matrix[np.first][np.second] >= matrix[p.first][p.second]) {
                        q.push(np);
                        atlantic.emplace(np);
                    }
                }
            }
            visited.emplace(p);
            q.pop();
        }
    }
};

vector<pair<int, int>> Solution::direction {
    { 1, 0 },
    { -1, 0 },
    { 0, 1 },
    { 0, -1 }
};

int main() {
    vector<vector<int>> mat {
        { 1, 2, 2, 3, 5 },
        { 3, 2, 3, 4, 4 },
        { 2, 4, 5 ,3, 1 },
        { 6, 7, 1, 4, 5 },
        { 5, 1, 1, 2, 4 }
    };
    for (auto &p: Solution().pacificAtlantic(mat)) {
        cout << "[" << p.first << "," << p.second << "]";
    }
    return 0;
}
