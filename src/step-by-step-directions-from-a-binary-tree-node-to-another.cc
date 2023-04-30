#include <algorithm>
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

class Solution {
public:
  string getDirections(TreeNode *root, int startValue, int destValue) {
    TreeNode *subRoot = lca(root, startValue, destValue);

    string path1, path2;
    toStart(subRoot, startValue, path1);
    toDest(subRoot, destValue, path2);
    std::reverse(path2.begin(), path2.end());
    return path1 + path2;
  }

  bool toStart(TreeNode *root, int p, string &path) {
    if (root == nullptr) {
      return false;
    }
    if (root->val == p) {
      return true;
    }

    if (toStart(root->left, p, path)) {
      path += "U";
      return true;
    }

    if (toStart(root->right, p, path)) {
      path += "U";
      return true;
    }

    return false;
  }

  bool toDest(TreeNode *root, int p, string &path) {
    if (root == nullptr) {
      return false;
    }
    if (root->val == p) {
      return true;
    }

    if (toDest(root->left, p, path)) {
      path += "L";
      return true;
    }
    if (toDest(root->right, p, path)) {
      path += "R";
      return true;
    }

    return false;
  }

  TreeNode *lca(TreeNode *root, int p, int q) {
    if (root == nullptr || root->val == p || root->val == q) {
      return root;
    }

    auto left = lca(root->left, p, q);
    auto right = lca(root->right, p, q);
    if (left == nullptr) {
      return right;
    }
    if (right == nullptr) {
      return left;
    }
    return root;
  }
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

int stringToInteger(string input) { return stoi(input); }

int main() {
  string line;
  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);
    getline(cin, line);
    int startValue = stringToInteger(line);
    getline(cin, line);
    int destValue = stringToInteger(line);

    string ret = Solution().getDirections(root, startValue, destValue);

    string out = (ret);
    cout << out << endl;
  }
  return 0;
}
