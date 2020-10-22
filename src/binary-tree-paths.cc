#include <iostream>
#include <vector>
#include <string>
#include <sstream>
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
    void searchPath(TreeNode *root, vector<string> &paths, string current) {
        if (root->left || root->right) {
            if (root->left) {
                string s = current + "->" + std::to_string(root->left->val);
                this->searchPath(root->left, paths, s);
            }
            if (root->right) {
                string s = current + "->" + std::to_string(root->right->val);
                this->searchPath(root->right, paths, s);
            } 
        } else {
            paths.push_back(current);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) {
            return vector<string>();
        }
        ostringstream ss;
        vector<string> paths;
        string path;
        this->searchPath(root, paths, std::to_string(root->val));
        return paths;
    }
};

int main() {
    return 0;
}
