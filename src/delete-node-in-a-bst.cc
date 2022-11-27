#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * Definition for a binary tree node.
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        enum { Left = 0, Right } position;
        TreeNode *parent = nullptr;
        auto *p = root;

        while (p->val != key) {
            parent = p;
            if (p->val > key) {
                position = Left;
                p = p->left;
            } else {
                position = Right;
                p = p->right;
            }
            if (p == nullptr) {
                return root;
            }
        }

        if (!p->left && !p->right) {
            delete p;
            if (parent == nullptr) {
                root = p = nullptr;
            } else if (position == Left) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
        } else if (p->left && !p->right) {
            auto *tmp = p;
            if (parent == nullptr) {
                root = p = p->left;
            } else if (position == Left) {
                parent->left = p->left;
            } else {
                parent->right = p->left;
            }
            delete tmp;
        } else {
            int value = this->findMinValueLargerThanCurrent(p);
            this->deleteNode(p, value);
            p->val = value;
        }
        return root;
    }

    int findMinValueLargerThanCurrent(TreeNode *root) {
        auto *p = root->right;
        int value = p->val;

        while (p->left != nullptr) {
            p = p->left;
            value = p->val;
        }

        return value;
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

int stringToInteger(string input) {
    return stoi(input);
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
        getline(cin, line);
        int key = stringToInteger(line);

        TreeNode* ret = Solution().deleteNode(root, key);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
