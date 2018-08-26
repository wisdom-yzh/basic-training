#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if (!root) {
            this->current = nullptr;
        } else {
            TreeNode *p = root;
            while (p != nullptr) {
                this->location.push(p);
                this->current = p;
                p = p->left;
                this->current->left = nullptr;
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return current != nullptr;
    }

    /** @return the next smallest number */
    int next() {
        int result = current->val;
        this->location.pop();
        if (!current->left && !current->right) {
            if (this->location.empty()) {
                this->current = nullptr;
            } else {
                this->current = this->location.top();
            }
        } else if (current->right) {
            auto p = current->right;
            this->current->right = nullptr;
            this->location.push(p);
            this->current = p;
            p = p->left;
            this->current->left = nullptr;
            while (p) {
                this->location.push(p);
                this->current = p;
                p = p->left;
                this->current->left = nullptr;
            }
        }
        return result;
    }

private:
    stack<TreeNode *> location;
    TreeNode *current;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

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
        BSTIterator iter(root);
        vector<int> ret;

        while (iter.hasNext()) {
            ret.push_back(iter.next());
        }

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
