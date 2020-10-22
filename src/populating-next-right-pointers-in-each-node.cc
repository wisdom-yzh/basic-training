#include <iostream>

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void recursion(TreeLinkNode *root, TreeLinkNode *next) {
        if (root == nullptr) {
            return;
        }
        root->next = next;
        this->recursion(root->left, root->right);
        if (next != nullptr) {
            this->recursion(root->right, next->left);
            this->recursion(next->left, next->right);
        }
    }

    void connect(TreeLinkNode *root) {
        return this->recursion(root, nullptr);
    }
};

int main() {
    return 0;
}
