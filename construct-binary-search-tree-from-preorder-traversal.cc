/**
 * Definition for a binary tree node.
 */
#include <algorithm>
#include <queue>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        if (preorder.size() == 1) {
            return new TreeNode(preorder[0]);
        }

        auto split = std::find_if(preorder.begin() + 1, preorder.end(), [&] (int &n) {
            return n >= *preorder.begin();
        });
        vector<int> leftChildVec(preorder.begin() + 1, split);
        vector<int> rightChildVec(split, preorder.end());

        auto *root = new TreeNode(*preorder.begin());
        root->left = bstFromPreorder(leftChildVec);
        root->right = bstFromPreorder(rightChildVec);
        return root;
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

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
        return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
            output += "null, ";
            continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> preorder = stringToIntegerVector(line);

        TreeNode* ret = Solution().bstFromPreorder(preorder);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
