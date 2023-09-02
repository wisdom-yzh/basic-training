#include <bits/stdc++.h>
#include <map>
#include <vector>
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

string treeNodeToString(TreeNode *root) {
  if (root == nullptr) {
    return "[]";
  }

  string output = "";
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();

    if (node == nullptr) {
      output += "null, ";
      continue;
    }

    output += to_string(node->val) + ", ";
    q.push(node->left);
    q.push(node->right);
  }
  return "[" + output.substr(0, output.length() - 2) + "]";
}

class Solution {
public:
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
    std::map<int, TreeNode *> dict;
    std::map<int, int> parentDict;

    for (auto &desc : descriptions) {
      int parentVal = desc[0], childVal = desc[1];
      bool isLeft = desc[2] == 1;
      TreeNode *parent, *child;

      auto iter = dict.find(parentVal);
      if (iter == dict.end()) {
        parent = new TreeNode(parentVal);
        dict.emplace(parentVal, parent);
      } else {
        parent = iter->second;
      }

      iter = dict.find(childVal);
      if (iter == dict.end()) {
        child = new TreeNode(childVal);
        dict.emplace(childVal, child);
      } else {
        child = iter->second;
      }

      if (isLeft) {
        parent->left = child;
      } else {
        parent->right = child;
      }
      parentDict[child->val] = parent->val;
      auto iter2 = parentDict.find(parent->val);
      if (iter2 == parentDict.end()) {
        parentDict.emplace(parent->val, 0);
      }
    }

    for (auto &[v, pv] : parentDict) {
      if (pv == 0) {
        return dict[v];
      }
    }
    return nullptr;
  }
};

int main() {
  vector<vector<vector<int>>> testCases{
      {{20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}},
      {{1, 2, 1}, {2, 3, 0}, {3, 4, 1}}};

  for (auto &descriptions : testCases) {
    cout << treeNodeToString(Solution().createBinaryTree(descriptions)) << endl;
  }
  return 0;
}
