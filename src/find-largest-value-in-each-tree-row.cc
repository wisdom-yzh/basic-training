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

class Solution {
public:
    struct TreeNodeWithDepth {
        TreeNode *pNode;
        int depth;
    };

    vector<int> largestValues(TreeNode* root) {
        vector<int> result;

        queue<TreeNodeWithDepth> q;
        q.push(TreeNodeWithDepth { root, 0 });

        while (!q.empty()) {
            auto & front = q.front();

            if (front.pNode == nullptr) {
                q.pop();
                continue;
            }

            if (front.depth >= result.size()) {
                result.push_back(front.pNode->val);
            } else {
                result[front.depth] = std::max(result[front.depth], front.pNode->val);
            }

            if (front.pNode->left != nullptr) {
                q.push(TreeNodeWithDepth { front.pNode->left, front.depth + 1 });
            }

            if (front.pNode->right != nullptr) {
                q.push(TreeNodeWithDepth { front.pNode->right, front.depth + 1 });
            }

            q.pop();
        }

        return result;
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);

        vector<int> ret = Solution().largestValues(root);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
