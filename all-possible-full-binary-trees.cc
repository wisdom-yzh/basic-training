#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    static vector<vector<TreeNode *>> memo;

public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if (N % 2 == 0) {
            return vector<TreeNode *>();
        }

        if (!memo[N].empty()) {
            return memo[N];
        }

        vector<TreeNode *> result;
        if (N == 1) {
            result.push_back(new TreeNode(0));
        } else {
            for (int i = 1; i <= N - 2; i++) {
                vector<TreeNode *> leftChildren = this->allPossibleFBT(i);
                vector<TreeNode *> rightChildren = this->allPossibleFBT(N - 1 - i);
                for (auto &left: leftChildren) {
                    for (auto &right: rightChildren) {
                        TreeNode *root = new TreeNode();
                        root->left = left;
                        root->right = right;
                        result.push_back(root);
                    }
                }
            }
        }

        memo[N] = result;
        return result;
    }
};

vector<vector<TreeNode *>> Solution::memo(21, vector<TreeNode *>{});

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    vector<TreeNode*> ret = Solution().allPossibleFBT(7);
    for (const auto &r: ret) {
        cout << treeNodeToString(r) << endl;
    }
    return 0;
}
