#include <iostream>
#include <vector>
#include <tuple>
#include <map>
using namespace std;

class UnionSet {
public:
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

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        UnionSet s(source.size());

        for (auto &as: allowedSwaps) {
            s.merge(as[0], as[1]);
        }

        int same = 0;
        map<int, map<int, int>> dict;
        for (int i = 0; i < source.size(); i++) {
            dict[s.find(i)][source[i]]++;
        }

        for (int i = 0; i < target.size(); i++) {
            int idx = s.find(i);
            if (dict[idx][target[i]] > 0) {
                same++;
                dict[idx][target[i]]--;
            }
        }

        return source.size() - same;
    }
};

int main() {
    vector<tuple<vector<int>, vector<int>, vector<vector<int>>>> testCases {
        {
            {1,2,3,4},
            {2,1,4,5},
            {{0,1},{2,3}},
        },
        {
            {1,2,3,4},
            {1,3,2,4},
            {}
        },
        {
            {5,1,2,4,3},
            {1,5,4,2,3},
            {{0,4},{4,2},{1,3},{1,4}}
        }
    };
    for (auto &[source, target, allowedSwaps]: testCases) {
        cout << Solution().minimumHammingDistance(source, target, allowedSwaps) << endl;
    }
    return 0;
}
