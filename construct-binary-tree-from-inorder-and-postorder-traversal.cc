#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recursionBuildTree(vector<int>::iterator &&inBegin,
            vector<int>::iterator &&inEnd,
            vector<int>::iterator &&postBegin,
            vector<int>::iterator &&postEnd) {
        if (inBegin == inEnd) {
            return nullptr;
        }

        int val = *(postEnd - 1);
        TreeNode *root = new TreeNode(val);

        int leftSubTreeLength = 0;
        auto p = inBegin;
        for (p = inBegin; p != inEnd; p++) {
            if (*p == val) {
                break;
            }
            leftSubTreeLength++;
        }

        root->left = this->recursionBuildTree(
            inBegin + 0, p + 0,
            postBegin + 0, postBegin + leftSubTreeLength
        );
        root->right = this->recursionBuildTree(
            p + 1, inEnd + 0,
            postBegin + leftSubTreeLength, postEnd - 1
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return this->recursionBuildTree(
            inorder.begin(), inorder.end(),
            postorder.begin(), postorder.end()
        );
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
        vector<int> inorder = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> postorder = stringToIntegerVector(line);

        TreeNode* ret = Solution().buildTree(inorder, postorder);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
