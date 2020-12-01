#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <queue>
#include <functional>
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionSet unionSet(s.size());

        for (auto &p: pairs) {
            unionSet.merge(p[0], p[1]);
        }

        vector<priority_queue<char, std::vector<char>, std::greater<char>>> unionStr(s.size());
        for (int i = 0; i < s.size(); i++) {
            unionStr[unionSet.find(i)].push(s[i]);
        }

        string str;
        for (int i = 0; i < s.size(); i++) {
            str += unionStr[unionSet.arr[i]].top();
            unionStr[unionSet.arr[i]].pop();
        }
        return str;
    }
};

int main() {
    vector<pair<string, vector<vector<int>>>> testCases {
        { "dcab", {{0,3},{1,2}} },
        { "dcab", {{0,3},{1,2},{0,2}} },
        { "cba",  {{0,1},{1,2}} },
        { "udyyek", {{3,3},{3,0},{5,1},{3,1},{3,4},{3,5}} }
    };
    for (auto &testCase: testCases) {
        cout << Solution().smallestStringWithSwaps(testCase.first, testCase.second) << endl;
    }
    return 0;
}
