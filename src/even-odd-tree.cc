#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
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
    bool isEvenOddTree(TreeNode* root) {
        std::queue<pair<int, TreeNode *>> q;
        q.emplace(0, root);

        int prevValue = 0, prevDepth = -1;

        while (!q.empty()) {
            auto &[currentDepth, p] = q.front();

            if (p->left != nullptr) {
                q.emplace(currentDepth + 1, p->left);
            }
            if (p->right != nullptr) {
                q.emplace(currentDepth + 1, p->right);
            }

            if (currentDepth != prevDepth) {
                if (((p->val + currentDepth) % 2) == 0) {
                    return false;
                }
                prevDepth = currentDepth;
                prevValue = p->val;
            } else {
                if ((p->val <= prevValue || (p->val % 2 == 0)) && (currentDepth % 2 == 0) ||
                    (p->val >= prevValue || (p->val % 2 != 0)) && (currentDepth % 2 != 0)) {
                    return false;
                }
                prevValue = p->val;
            }

            q.pop();
        }

        return true;
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

        bool ret = Solution().isEvenOddTree(root);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
