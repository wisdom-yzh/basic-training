#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <string>
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
    int countPairs(TreeNode* root, int distance) {
        int res = 0;
        dfs(root, 0, res, distance);
        return res;
    }

    vector<int> dfs(TreeNode *root, int depth, int &res, int distance) {
        if (!root->left && !root->right) {
            return vector<int>(1, depth);
        }

        vector<int> left, right;
        if (root->left) {
            left = dfs(root->left, depth + 1, res, distance);
        }
        if (root->right) {
            right = dfs(root->right, depth + 1, res, distance);
        }

        for (int i = 0; i < left.size(); i++) {
            for (int j = 0; j < right.size(); j++) {
                if (left[i] + right[j] - depth - depth <= distance) {
                    res++;
                }
            }
        }

        vector<int> children = left;
        children.insert(children.end(), right.begin(), right.end());
        return children;
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

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int distance = stringToInteger(line);

        int ret = Solution().countPairs(root, distance);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
