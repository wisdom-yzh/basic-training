#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int nodeCount = 0, valueCount = 0;
        return moveCount(root, nodeCount, valueCount);
    }

    int moveCount(TreeNode *root, int &nodeCount, int &valueCount) {
        if (root == nullptr) {
            nodeCount = valueCount = 0;
            return 0;
        }

        int leftNodeCount = 0, leftValueCount = 0, rightNodeCount = 0, rightValueCount = 0;
        int leftMoveCount = moveCount(root->left, leftNodeCount, leftValueCount);
        int rightMoveCount = moveCount(root->right, rightNodeCount, rightValueCount);
        int moveCount = leftMoveCount + rightMoveCount +
            std::abs(leftValueCount - leftNodeCount) +
            std::abs(rightValueCount - rightNodeCount);

        nodeCount = 1 + leftNodeCount + rightNodeCount;
        valueCount = root->val + leftValueCount + rightValueCount;
        return moveCount;
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

        int ret = Solution().distributeCoins(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
