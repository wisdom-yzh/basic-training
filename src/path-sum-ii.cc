#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
  void recursionPathSum(TreeNode *root, vector<vector<int>> &result,
                        vector<int> &current, int sum) {
    if (root == nullptr) {
      return;
    }
    if (root->left == nullptr && root->right == nullptr) {
      if (root->val == sum) {
        current.push_back(root->val);
        result.push_back(current);
        current.pop_back();
      }
      return;
    }
    current.push_back(root->val);
    if (root->left) {
      this->recursionPathSum(root->left, result, current, sum - root->val);
    }
    if (root->right) {
      this->recursionPathSum(root->right, result, current, sum - root->val);
    }
    current.pop_back();
  }

  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    vector<vector<int>> result;
    vector<int> current;
    this->recursionPathSum(root, result, current, sum);
    return result;
  }
};

int main() { return 0; }
