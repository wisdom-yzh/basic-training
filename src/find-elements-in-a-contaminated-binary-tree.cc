#include <iostream>
#include <set>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class FindElements {
private:
    std::set<int> elements;

public:
    FindElements(TreeNode* root) {
        recovery(root, 0);
    }

    void recovery(TreeNode *root, int value) {
        if (root == nullptr) {
            return;
        }
        elements.emplace(value);
        root->val = value;
        recovery(root->left, 2 * value + 1);
        recovery(root->right, 2 * value + 2);
    }

    bool find(int target) {
        return elements.find(target) != elements.end();
    }
};

int main() {
    return 0;
}
