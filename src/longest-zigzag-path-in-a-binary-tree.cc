#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <algorithm>
#include <cassert>
#include <map>
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
    enum FROM {
        LEFT = 0,
        RIGHT,
    };

    vector<map<TreeNode *, int>> dp;

    int longestZigZag(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int res = 1;
        dp.resize(2);
        dp[LEFT][root] = dp[RIGHT][root] = 1;

        std::queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            auto *p = q.front();
            q.pop();

            if (p->right) {
                q.push(p->right);
                int left = dp[LEFT][p];
                if (!left) {
                    left = 1;
                }
                left++;
                dp[RIGHT][p->right] = left;
                res = std::max(left, res);
            }

            if (p->left) {
                q.push(p->left);
                int right = dp[RIGHT][p];
                if (!right) {
                    right = 1;
                }
                right++;
                dp[LEFT][p->left] = right;
                res = std::max(right, res);
            }
        }

        return res - 1;
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

        int ret = Solution().longestZigZag(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
