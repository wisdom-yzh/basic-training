#include <vector>
#include <tuple>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> deps(numCourses, vector<bool>(numCourses, false));
        for (auto &p: prerequisites) {
            deps[p[0]][p[1]] = true;
        }

        for (int i = 0; i < numCourses; i++){
            for (int j = 0; j < numCourses; j++){
                for (int k = 0; k < numCourses; k++){
                    if (deps[j][i] && deps[i][k]) {
                        deps[j][k] = true;
                    }
                }
            }
        }

        vector<bool> result;
        for (auto &q: queries) {
            result.push_back(deps[q[0]][q[1]]);
        }
        return result;
    }
};

int main() {
    vector<tuple<int, vector<vector<int>>, vector<vector<int>>>> testCases {
        { 2, {{1,0}}, {{0,1},{1,0}} },
        { 2, {}, {{1,0},{0,1}} },
        { 3, {{1,2},{1,0},{2,0}}, {{1,0},{1,2}} },
        { 3, {{1,0},{2,0}}, {{0,1},{2,0}} },
        { 5, {{0,1},{1,2},{2,3},{3,4}}, {{0,4},{4,0},{1,3},{3,0}} }
    };

    for (auto &t: testCases) {
        for (const auto &x: Solution().checkIfPrerequisite(get<0>(t), get<1>(t), get<2>(t))) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
