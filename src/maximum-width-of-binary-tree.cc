#include <algorithm>
#include <string>
#include <queue>
#include <iostream>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    struct TreeItem {
        uint32_t index;
        uint32_t depth;
        TreeNode *t;
        TreeItem(uint32_t index, uint32_t depth, TreeNode *t): index(index), depth(depth), t(t) {}
    };

    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        std::queue<TreeItem> q;
        uint32_t leftIndex = 0, rightIndex = 0;
        int depth = -1, maxWidth = 0;

        q.push(TreeItem(0, 0, root));
        while (!q.empty()) {
            auto item = std::move(q.front());
            q.pop();

            if (item.t->left) {
                q.push(TreeItem(2 * item.index, item.depth + 1, item.t->left));
            }
            if (item.t->right) {
                q.push(TreeItem(2 * item.index + 1, item.depth + 1, item.t->right));
            }

            if (depth != item.depth) {
                maxWidth = std::max(maxWidth, static_cast<int>(rightIndex - leftIndex + 1));
                leftIndex = rightIndex = item.index;
                depth = item.depth;
            } else {
                rightIndex = item.index;
            }
        }

        return std::max(maxWidth, static_cast<int>(rightIndex - leftIndex + 1));
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

        int ret = Solution().widthOfBinaryTree(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
