#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    TreeNode *recursionBuildTree(vector<int>::iterator &&preBegin, vector<int>::iterator &&preEnd,
            vector<int>::iterator &&inBegin, vector<int>::iterator &&inEnd) {
        if (preBegin == preEnd) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(*preBegin);
        int leftSubTreeLength = 0;

        for (auto iter = inBegin; iter != inEnd; iter++) {
            if (*iter == *preBegin) {
                break;
            }
            leftSubTreeLength++;
        }

        root->left = this->recursionBuildTree(preBegin + 1, preBegin + 1 + leftSubTreeLength,
                inBegin + 0, inBegin + leftSubTreeLength);
        root->right = this->recursionBuildTree(preBegin + 1 + leftSubTreeLength, preEnd + 0,
                inBegin + leftSubTreeLength + 1, inEnd + 0);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return this->recursionBuildTree(preorder.begin(), preorder.end(),
                inorder.begin(), inorder.end());
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
        getline(cin, line);
        vector<int> inorder = stringToIntegerVector(line);
        TreeNode* ret = Solution().buildTree(preorder, inorder);
        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
