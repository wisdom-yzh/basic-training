#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
#include <string>
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return this->constructFromPrePost(pre.begin(), pre.end(), post.begin(), post.end());
    }

    TreeNode* constructFromPrePost(vector<int>::iterator preBegin, vector<int>::iterator preEnd,
            vector<int>::iterator postBegin, vector<int>::iterator postEnd) {
        if (preBegin == preEnd) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(*preBegin);
        if (preBegin + 1 == preEnd) {
            return root;
        }

        auto rightChildValue = *(postEnd - 2);
        int size = 0;
        auto iter = preBegin + 1;
        for (; iter != preEnd; iter++) {
            if (*iter == rightChildValue) {
                size = std::distance(preBegin + 1, iter);
                break;
            }
        }

        root->left = this->constructFromPrePost(preBegin + 1, iter, postBegin, postBegin + size);
        root->right = this->constructFromPrePost(iter, preEnd, postBegin + size, postEnd - 1);

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
        vector<int> pre = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> post = stringToIntegerVector(line);

        TreeNode* ret = Solution().constructFromPrePost(pre, post);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
