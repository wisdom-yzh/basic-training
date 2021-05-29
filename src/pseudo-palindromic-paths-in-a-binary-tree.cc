#include <iostream>
#include <sstream>
#include <queue>
#include <string>
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
    int pseudoPalindromicPaths(TreeNode* root) {
        int count = 0;
        vector<int> arr(10, 0);
        dfs(root, arr, count);
        return count;
    }

    void dfs(TreeNode *root, vector<int> &arr, int &count) {
        arr[root->val]++;

        if (root->left == nullptr && root->right == nullptr) {
            int oddNum = 0;
            for (int i = 0; i < 10; i++) {
                if (arr[i] % 2 != 0) {
                    oddNum++;
                }
                if (oddNum > 1) {
                    break;
                }
            }
            if (oddNum <= 1) {
                count++;
            }
        } else {
            if (root->left != nullptr) {
                dfs(root->left, arr, count);
            }
            if (root->right != nullptr) {
                dfs(root->right, arr, count);
            }
        }

        arr[root->val]--;
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

        int ret = Solution().pseudoPalindromicPaths (root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
