#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool result = false;
        if (s == nullptr && t == nullptr) {
            return true;
        }
        if(s == nullptr || t == nullptr) {
            return false;
        }
        if (s->val == t->val) {
            result = isSame(s->left, t->left) &&
                isSame(s->right, t->right);
        }
        if (!result) {
            result = isSubtree(s->left, t);
        }
        if (!result) {
            result = isSubtree(s->right, t);
        }
        return result;
    }

    bool isSame(TreeNode *s, TreeNode *t) {
        if (s == nullptr && t == nullptr) {
            return true;
        }
        if (s != nullptr && t != nullptr) {
            return s->val == t->val &&
                isSame(s->left, t->left) &&
                isSame(s->right, t->right);
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* s = stringToTreeNode(line);
        getline(cin, line);
        TreeNode* t = stringToTreeNode(line);

        bool ret = Solution().isSubtree(s, t);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
