#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        auto *xNode = find(root, x);

        int leftCount = count(xNode->left);
        int rightCount = count(xNode->right);
        int parentCount = n - leftCount - rightCount- 1;

        return leftCount + rightCount < parentCount ||
            leftCount + parentCount < rightCount ||
            rightCount + parentCount < leftCount;
    }

    int count(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + count(root->left) + count(root->right);
    }

    TreeNode *find(TreeNode *root, int x) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == x) {
            return root;
        }
        auto *left = find(root->left, x);
        if (left != nullptr) {
            return left;
        }
        return find(root->right, x);
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int n = stringToInteger(line);
        getline(cin, line);
        int x = stringToInteger(line);

        bool ret = Solution().btreeGameWinningMove(root, n, x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
