#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        std::set<int> s;
        for (int i = 0; i < n; i++) {
            s.emplace(i);
        }

        for (auto &i: leftChild) {
            if (i == -1) {
                continue;
            }
            auto iter = s.find(i);
            if (iter == s.end()) {
                return false;
            }
            s.erase(iter);
        }

        for (auto &i: rightChild) {
            if (i == -1) {
                continue;
            }
            auto iter = s.find(i);
            if (iter == s.end()) {
                return false;
            }
            s.erase(iter);
        }

        if (s.size() != 1) {
            return false;
        }

        int root = *s.begin();
        vector<bool> visited(n, false);
        std::queue<int> q;
        q.push(root);
        visited[root] = true;

        while (!q.empty()) {
            int idx = q.front();
            q.pop();

            if (leftChild[idx] != -1) {
                if (visited[leftChild[idx]]) {
                    return false;
                }
                visited[leftChild[idx]] = true;
                q.push(leftChild[idx]);
            }

            if (rightChild[idx] != -1) {
                if (visited[rightChild[idx]]) {
                    return false;
                }
                visited[rightChild[idx]] = true;
                q.push(rightChild[idx]);
            }
        }

        for (const auto &v: visited) {
            if (!v) {
                return false;
            }
        }
        return true;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                return !isspace(ch);
                }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        vector<int> leftChild = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> rightChild = stringToIntegerVector(line);

        bool ret = Solution().validateBinaryTreeNodes(n, leftChild, rightChild);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
