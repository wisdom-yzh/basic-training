#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    struct UnionSet {
        UnionSet(size_t size) {
            arr.assign(size, 0);
            for (int i = 0; i < size; i++) {
                arr[i] = i;
            }
        }

        int find(int x) {
            int root = x;
            while (root != arr[root]) {
                root = arr[root];
            }
            while (root != x) { // 路径压缩
                int tmp = arr[x];
                arr[x] = root;
                x = tmp;
            }
            return root;
        }

        void merge(int x, int y) {
            arr[find(x)] = arr[find(y)];
        }

        vector<int> arr;
    };

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n > connections.size() + 1) {
            return -1;
        }

        UnionSet s(n);
        for (auto &conn: connections) {
            s.merge(conn[0], conn[1]);
        }

        int root = s.find(0);
        int result = 0;
        for (int i = 1; i < n; i++) {
            if (s.find(i) != root) {
                s.merge(i, root);
                result++;
            }
        }
        return result;
    }
};

int main() {
    vector<pair<int, vector<vector<int>>>> testCases {
        { 4, {{0,1},{0,2},{1,2}} },
        { 6, {{0,1},{0,2},{0,3},{1,2},{1,3}} },
        { 5, {{0,1},{0,2},{3,4},{2,3}} }
    };
    for (auto &testCase: testCases) {
        cout << Solution().makeConnected(testCase.first, testCase.second) << endl;
    }
    return 0;
}
