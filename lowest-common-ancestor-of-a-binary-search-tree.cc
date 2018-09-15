#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode *root, TreeNode *p, vector<TreeNode *> &path) {
        if (root == nullptr) {
            return false;
        }
        path.push_back(root);
        if (root == p) {
            return true;
        }
        if (!findPath(root->left, p, path) &&
            !findPath(root->right, p, path)) {
            path.pop_back();
            return false;
        } 
        return true;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> vp, vq;
        findPath(root, p, vp);
        findPath(root, q, vq);
        TreeNode *result = root;
        for (auto i = vp.begin(), j = vq.begin();
            i != vp.end() - 1 && j != vq.end() - 1;
            i++, j++) {
            if (*(i + 1) == *(j + 1)) {
                result = *(i + 1);
            } else {
                break;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
