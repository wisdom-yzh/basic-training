#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
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
    vector<TreeNode*> recursionGenerateTrees(int left, int right) {
        vector<TreeNode *> result;
        if (left > right) {
            result.push_back(nullptr);
            return result;
        }
        if (left == right) {
            result.push_back(new TreeNode(left));
            return result;
        }
        
        for (int p = left; p <= right; p++) {
            vector<TreeNode*> leftChildList = this->recursionGenerateTrees(left, p - 1);
            vector<TreeNode*> rightChildList = this->recursionGenerateTrees(p + 1, right);
            for (auto &&rightChild: rightChildList) {
                for (auto &&leftChild: leftChildList) {
                    TreeNode *root = new TreeNode(p);
                    root->left = leftChild;
                    root->right = rightChild;
                    result.push_back(root);
                }
            }
        }
        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode *>(0);
        }
        return this->recursionGenerateTrees(1, n);
    }
};

int main() {
    vector<TreeNode*> result = Solution().generateTrees(3);
    for (auto &&tree: result) {
        queue<TreeNode *> q;
        q.push(tree);
        while (!q.empty()) {
            TreeNode *p = q.front();
            if (p != nullptr) {
                cout << p->val << ',';
                if (p->left != nullptr || p->right != nullptr) {
                    q.push(p->left);
                    q.push(p->right);
                }
            } else {
                cout << "null,";
            }
            q.pop();
        }

        cout << endl;
    }
    return 0;
}
