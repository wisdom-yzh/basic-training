#include <iostream>
#include <sstream>
#include <queue>
#include <algorithm>
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
    bool recursionIsValidBST(TreeNode *root, int &min, int &max) {
        int lmin, lmax, rmin, rmax;
        bool left, right;
        bool result = true;

        min = max = root->val;

        if (root->left) {
            left = recursionIsValidBST(root->left, lmin, lmax);
            result &= (left && lmax < root->val);
            min = lmin;
        }
        if (root->right) {
            right = recursionIsValidBST(root->right, rmin, rmax);
            result &= (right && rmin > root->val);
            max = rmax;
        }
        return result;
    }

    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        int lmin, lmax, rmin, rmax;
        bool left, right;
        bool result = true;
        if (root->left) {
            left = recursionIsValidBST(root->left, lmin, lmax);
            result &= (left && lmax < root->val);
        }
        if (root->right) {
            right = recursionIsValidBST(root->right, rmin, rmax);
            result &= (right && rmin > root->val);
        }
        return result;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);

        bool ret = Solution().isValidBST(root);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
