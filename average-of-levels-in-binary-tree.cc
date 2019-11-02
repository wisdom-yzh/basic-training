#include <vector>
#include <iostream>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> data;
        traverse(root, data, 0);
        vector<double> result;

        for (auto &arr: data) {
            int64_t sum = 0;
            for (auto &item: arr) {
                sum += item;
            }
            result.push_back(sum / (double)arr.size());
        }

        return result;
    }

    void traverse(TreeNode *root, vector<vector<int>> &data, int depth) {
        if (root == nullptr) {
            return;
        }
        if (depth == data.size()) {
            data.push_back(vector<int> { root->val } );
        } else {
            data[depth].push_back(root->val);
        }

        traverse(root->left, data, depth + 1);
        traverse(root->right, data, depth + 1);
    }
};

int main() {
    return 0;
}
