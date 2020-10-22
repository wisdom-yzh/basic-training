#include <string>
#include <map>
#include <queue>
#include <iterator>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        std::map<std::string, int> treeSet;
        vector<TreeNode *> result;

        if (root == nullptr) {
            return result;
        }
        if (root->left) {
            this->dfs(root->left, treeSet, result);
        }
        if (root->right) {
            this->dfs(root->right, treeSet, result);
        }
        return result;
    }

private:
    string dfs(TreeNode *root, std::map<std::string, int> &treeSet, vector<TreeNode *> &result) {
        string symbol = "", leftSymbol = "", rightSymbol = "";
        if (root->left) {
            leftSymbol = dfs(root->left, treeSet, result);
        }
        if (root->right) {
            rightSymbol = dfs(root->right, treeSet, result);
        }
        symbol = "(" + std::move(leftSymbol) + std::to_string(root->val) + std::move(rightSymbol) + ")";
        auto iter = treeSet.find(symbol);
        if (iter == treeSet.end()) {
            treeSet.insert(std::make_pair(symbol, 1));
        } else if (iter->second == 1) {
            result.push_back(root);
            iter->second = 2;
        }

        return symbol;
    }
};

int main() {
    return 0;
}
