#include <iostream>
using namespace std;

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
        TreeLinkNode *p = root->right ? root->right : root->left;
        while (next && !next->left && !next->right) {
            next = next->next;
        }
        if (!next) {
            this->recursion(p, nullptr);
        } else {
            if (next->left && next->right) {
                this->recursion(next->left, next->right);
                this->recursion(p, next->left);
            } else if (next->left) {
                this->recursion(p, next->left);
            } else if (next->right) {
                this->recursion(p, next->right);
            } else {
                this->recursion(p, nullptr);
            }
        }
        if (root->left && root->right) {
            this->recursion(root->left, root->right);
        }
    }

    void connect(TreeLinkNode *root) {
        return this->recursion(root, nullptr);
    }
};

int main() {
    return 0;
}
