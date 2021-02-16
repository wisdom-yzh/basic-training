#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

/**
 *  Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    const static int MOD = 1e9 + 7;

    int maxProduct(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int s = sum(root);
        uint64_t val = 0;
        checkMax(root, s, val);
        return val % MOD;
    }

    int sum(TreeNode* root) {
        if (root->left != nullptr) {
            root->val += sum(root->left);
        }
        if (root->right != nullptr) {
            root->val += sum(root->right);
        }
        return root->val;
    }

    void checkMax(TreeNode *root, int s, uint64_t &val) {
        if (root->left) {
            checkMax(root->left, s, val);
            val = std::max(val, (uint64_t)root->left->val * (s - root->left->val));
        }
        if (root->right)  {
            checkMax(root->right, s, val);
            val = std::max(val, (uint64_t)root->right->val * (s - root->right->val));
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

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);

        int ret = Solution().maxProduct(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
