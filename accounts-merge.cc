#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        std::vector<std::queue<int>> edge(accounts.size());
        std::vector<bool> merged(accounts.size(), false);
        std::unordered_map<std::string, int> mailIndex;

        for (int i = 0; i != accounts.size(); i++) {
            std::set<string> uniqueSet;
            for (auto j = 1; j < accounts[i].size(); j++) {
                uniqueSet.emplace(accounts[i][j]);
            }
            vector<string> newVec;
            newVec.push_back(accounts[i][0]);

            int j = 1;
            for (auto p = uniqueSet.begin(); p != uniqueSet.end(); p++) {
                newVec.push_back(*p);
                auto iter = mailIndex.find(*p);
                if (iter == mailIndex.end()) {
                    mailIndex.emplace(*p, i);
                } else {
                    edge[i].push(iter->second);
                    edge[iter->second].push(i);
                }
                j++;
            }
            accounts[i] = std::move(newVec);
        }

        vector<vector<string>> result;
        for (int i = 0; i < accounts.size(); i++) {
            if (merged[i]) {
                continue;
            }
            merged[i] = true;
            auto &q = edge[i];
            while (!q.empty()) {
                auto index = q.front();
                q.pop();
                if (merged[index]) {
                    continue;
                }
                merged[index] = true;
                mergeAccount(accounts[i], accounts[index]);
                while (!edge[index].empty()) {
                    q.push(edge[index].front());
                    edge[index].pop();
                }
            }
            result.push_back(std::move(accounts[i]));
        }

        return result;
    }

    void mergeAccount(vector<string> &A, vector<string> &B) {
        vector<string> result;
        result.push_back(A[0]);

        int i = 1, j = 1;
        while (i < A.size() || j < B.size()) {
            if (i < A.size() && j < B.size()) {
                if (A[i] == B[j]) {
                    result.push_back(A[i]);
                    i++;
                    j++;
                } else if (A[i] > B[j]) {
                    result.push_back(B[j]);
                    j++;
                } else {
                    result.push_back(A[i]);
                    i++;
                }
            } else if (i == A.size()) {
                result.push_back(B[j]);
                j++;
            } else if (j == B.size()) {
                result.push_back(A[i]);
                i++;
            }
        }

        A = std::move(result);
    }
};

int main() {
    vector<vector<string>> accounts {
        {"John", "johnsmith@mail.com", "john00@mail.com", "johnsmith@mail.com"},
        {"John", "johnnybravo@mail.com", "johnnybravo@mail.com"},
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"Mary", "mary@mail.com"}
    };
    for (auto &row: Solution().accountsMerge(accounts)) {
        for (auto &col: row) {
            cout << col << ',';
        }
        cout << endl;
    }
    return 0;
}
