#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    struct TreeNode {
        TreeNode(): s(""), exist(false) {}
        TreeNode(string &s, bool exist = false): s(s), exist(exist) {}
        std::unordered_map<string, shared_ptr<TreeNode>> children;
        std::string s;
        bool exist;
    };

    void addStr(shared_ptr<TreeNode> &root, string &&s) {
        auto p = root;
        std::istringstream iss(s);
        for (string line; std::getline(iss, line, '/'); ) {
            auto iter = p->children.find(line);
            if (iter == p->children.end()) {
                auto res = p->children.emplace(line, make_shared<TreeNode>(line, false));
                p = res.first->second;
            } else {
                p = iter->second;
            }
        }
        p->exist = true;
    }

    void display(string &&prefix, shared_ptr<TreeNode> &root, vector<string> &result) {
        if (root->exist) {
            result.push_back(prefix + "/" + root->s);
            return;
        }

        for (auto &p: root->children) {
            if (root->s.empty()) {
                display(prefix + root->s, p.second, result);
            } else {
                display(prefix + "/" + root->s, p.second, result);
            }
        }
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        shared_ptr<TreeNode> root = make_shared<TreeNode>();
        for (auto &f: folder) {
           addStr(root, f.substr(1) + "/");
        }

        vector<string> res;
        display("", root, res);
        return res;
    }
};

int main() {
    vector<vector<string>> testCases {
        {"/a","/a/b","/c/d","/c/d/e","/c/f"},
        {"/a","/a/b/c","/a/b/d"},
        {"/a/b/c","/a/b/ca","/a/b/d"}
    };
    for (auto &testCase: testCases) {
        for (auto &item: Solution().removeSubfolders(testCase)) {
            cout << item << ' ';
        }
        cout << endl;
    }
    return 0;
}
