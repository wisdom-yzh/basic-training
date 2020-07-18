#include <iostream>
#include <stack>
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

class CBTInserter {
public:
    CBTInserter(TreeNode* root): root(root) {
        size = this->getSize(root);
    }

    int insert(int v) {
        int index = (size - 1) / 2;
        stack<int> stk;

        while (index != 0) {
            stk.push(index % 2);
            index = (index - 1) / 2;
        }

        auto newNode = new TreeNode(v);
        auto *p = root;
        while (!stk.empty()) {
            if (stk.top() % 2 == 0) {
                p = p->right;
            } else {
                p = p->left;
            }
            stk.pop();
        }

        if (size % 2 == 0) {
            p->right = newNode;
        } else {
            p->left = newNode;
        }
        size++;
        return p->val;
    }

    TreeNode* get_root() {
        return root;
    }

private:

    int getSize(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + getSize(root->left) + getSize(root->right);
    }

    TreeNode *root;
    int size;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
int main() {
    return 0;
}
