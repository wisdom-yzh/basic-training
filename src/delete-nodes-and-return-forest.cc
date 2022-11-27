#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> s(to_delete.begin(), to_delete.end());
        vector<TreeNode *> result;
        dfs(s, result, root, true);
        return result;
    }

    TreeNode *dfs(set<int> &s, vector<TreeNode *> &result, TreeNode *root, bool parentDel) {
        if (root == nullptr) {
            return nullptr;
        }

        if (s.find(root->val) == s.end()) {
            root->left = dfs(s, result, root->left, false);
            root->right = dfs(s, result, root->right, false);
            if (parentDel) {
                result.push_back(root);
            }
            return root;
        }

        root->left = dfs(s, result, root->left, true);
        root->right = dfs(s, result, root->right, true);
        return nullptr;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    vector<int> toDel {2, 1};
    Solution().delNodes(root, toDel);
    return 0;
}
