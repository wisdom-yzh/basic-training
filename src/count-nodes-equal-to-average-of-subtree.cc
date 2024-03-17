#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void trimLeftTrailingSpaces(string &input) {
  input.erase(input.begin(), find_if(input.begin(), input.end(),
                                     [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input) {
  input.erase(
      find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); })
          .base(),
      input.end());
}

TreeNode *stringToTreeNode(string input) {
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  if (!input.size()) {
    return nullptr;
  }

  string item;
  stringstream ss;
  ss.str(input);

  getline(ss, item, ',');
  TreeNode *root = new TreeNode(stoi(item));
  queue<TreeNode *> nodeQueue;
  nodeQueue.push(root);

  while (true) {
    TreeNode *node = nodeQueue.front();
    nodeQueue.pop();

    if (!getline(ss, item, ',')) {
      break;
    }

    trimLeftTrailingSpaces(item);
    if (item != "null") {
      int leftNumber = stoi(item);
      node->left = new TreeNode(leftNumber);
      nodeQueue.push(node->left);
    }

    if (!getline(ss, item, ',')) {
      break;
    }

    trimLeftTrailingSpaces(item);
    if (item != "null") {
      int rightNumber = stoi(item);
      node->right = new TreeNode(rightNumber);
      nodeQueue.push(node->right);
    }
  }
  return root;
}

class Solution {
public:
  int averageOfSubtree(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int count = 0, sum = 0, res = 0;
    recursiveCount(root, count, sum, res);
    return res;
  }

  void recursiveCount(TreeNode *root, int &nodeCount, int &nodeSum, int &res) {
    int leftCount = 0, leftSum = 0, rightCount = 0, rightSum = 0;
    if (root->left != nullptr) {
      recursiveCount(root->left, leftCount, leftSum, res);
    }
    if (root->right != nullptr) {
      recursiveCount(root->right, rightCount, rightSum, res);
    }

    nodeCount = leftCount + rightCount + 1;
    nodeSum = leftSum + rightSum + root->val;
    if (root->val == nodeSum / nodeCount) {
      res++;
    }
  }
};

int main() {
  string line;
  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);

    int ret = Solution().averageOfSubtree(root);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
