#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return this->recursiveConstructMaximumBinaryTree(nums, 0, nums.size() - 1);
    }

    TreeNode* recursiveConstructMaximumBinaryTree(vector<int> &nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        if (left == right) {
            return new TreeNode(nums[left]);
        }

        TreeNode *root = new TreeNode(0);
        int mid = left, maxValue = nums[left];
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                mid = i;
            }
        }

        root->val = nums[mid];
        root->left = this->recursiveConstructMaximumBinaryTree(nums, left, mid - 1);
        root->right = this->recursiveConstructMaximumBinaryTree(nums, mid + 1, right);
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
        vector<int> nums = stringToIntegerVector(line);

        TreeNode* ret = Solution().constructMaximumBinaryTree(nums);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
