#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <string>
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
    struct ExtendedTreeNode {
        TreeNode *pNode;
        int depth;
    };

    int findBottomLeftValue(TreeNode* root) {
        int bottomLeftValue = 0;
        int currentDepth = -1;
        std::queue<ExtendedTreeNode> q;

        q.push(ExtendedTreeNode{ root, 0 });

        while (!q.empty()) {
            auto current = q.front();
            if (currentDepth < current.depth) {
                bottomLeftValue = current.pNode->val;
                currentDepth = current.depth;
            }

            q.pop();

            if (current.pNode->left) {
                q.push(ExtendedTreeNode{ current.pNode->left, current.depth + 1});
            }
            if (current.pNode->right) {
                q.push(ExtendedTreeNode{ current.pNode->right, current.depth + 1});
            }
        }

        return bottomLeftValue;
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

        int ret = Solution().findBottomLeftValue(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
