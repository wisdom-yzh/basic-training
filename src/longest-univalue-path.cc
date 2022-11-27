#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int longestUnivaluePath = 0;
        this->recursiveLongestUnivaluePathByRoot(root, longestUnivaluePath);
        return longestUnivaluePath;
    }

    int recursiveLongestUnivaluePathByRoot(TreeNode *root, int &longestUnivaluePath) {
        int valueByRoot = 0, valueTree = 0, valueLTree = 0, valueRTree = 0;
        if (root->left != nullptr) {
            valueLTree = this->recursiveLongestUnivaluePathByRoot(root->left, longestUnivaluePath);
            if (root->left->val == root->val) {
                valueByRoot = std::max(valueByRoot, valueLTree + 1);
                valueTree += valueLTree + 1;
            }
        }
        if (root->right != nullptr) {
            valueRTree = this->recursiveLongestUnivaluePathByRoot(root->right, longestUnivaluePath);
            if (root->right->val == root->val) {
                valueByRoot = std::max(valueByRoot, valueRTree + 1);
                valueTree += valueRTree + 1;
            }
        }
        longestUnivaluePath = std::max(longestUnivaluePath, valueTree);
        longestUnivaluePath = std::max(longestUnivaluePath, valueByRoot);
        return valueByRoot;
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

        int ret = Solution().longestUnivaluePath(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
