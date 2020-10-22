#include <iostream>
#include <sstream>
#include <queue>
#include <algorithm>
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
    bool isCousins(TreeNode* root, int x, int y) {
        if (root->val == x || root->val == y) {
            return false;
        }
        pair<int, int> xLocation, yLocation;
        getLocation(root, 0, x, xLocation);
        getLocation(root, 0, y, yLocation);

        return xLocation.first == yLocation.first && xLocation.second != yLocation.second;
    }

    bool getLocation(TreeNode *root, int depth, int num, pair<int, int> &location) {
        if (root->left != nullptr) {
            if (root->left->val == num) {
                location.first = depth;
                location.second = root->val;
                return true;
            }

            if (getLocation(root->left, depth + 1, num, location)) {
                return true;
            }
        }

        if (root->right != nullptr) {
            if (root->right->val == num) {
                location.first = depth;
                location.second = root->val;
                return true;
            }

            if (getLocation(root->right, depth + 1, num, location)) {
                return true;
            }
        }

        return false;
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
        int x = stringToInteger(line);
        getline(cin, line);
        int y = stringToInteger(line);

        bool ret = Solution().isCousins(root, x, y);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
