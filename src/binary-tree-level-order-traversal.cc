#include <queue>
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    queue<std::pair<TreeNode *, int>> q;
    vector<vector<int>> result;

    if (root == nullptr) {
      return vector<vector<int>>();
    }

    q.push(std::make_pair(root, 0));

    while (!q.empty()) {
      auto top = q.front();
      if (top.second >= (int)result.size()) {
        result.push_back(vector<int>{top.first->val});
      } else {
        result[top.second].push_back(top.first->val);
      }
      if (top.first->left != nullptr) {
        q.push(std::make_pair(top.first->left, top.second + 1));
      }
      if (top.first->right != nullptr) {
        q.push(std::make_pair(top.first->right, top.second + 1));
      }
      q.pop();
    }

    return result;
  }
};

int main() { return 0; }
