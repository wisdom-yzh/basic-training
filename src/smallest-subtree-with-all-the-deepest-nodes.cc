#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxDepth = 0;
        return this->recursion(root, 0, maxDepth);
    }

    TreeNode *recursion(TreeNode *root, int depth, int &maxDepth) {
        // root is leaf
        if (root->left == nullptr && root->right == nullptr) {
            maxDepth = depth;
            return root;
        }

        TreeNode *pLeft = nullptr, *pRight = nullptr;
        int leftMaxDepth = 0, rightMaxDepth = 0;
        if (root->left) {
            pLeft = this->recursion(root->left, depth + 1, leftMaxDepth);
        }
        if (root->right) {
            pRight = this->recursion(root->right, depth + 1, rightMaxDepth);
        }

        if (leftMaxDepth == rightMaxDepth) {
            maxDepth = leftMaxDepth;
            return root;
        } else if (leftMaxDepth > rightMaxDepth) {
            maxDepth = leftMaxDepth;
            return pLeft;
        } else {
            maxDepth = rightMaxDepth;
            return pRight;
        }
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
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
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
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

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
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

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);

        TreeNode* ret = Solution().subtreeWithAllDeepest(root);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
