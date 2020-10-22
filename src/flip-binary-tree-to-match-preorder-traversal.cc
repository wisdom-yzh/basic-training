#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <sstream>
#include <string>
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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> flips;
        if (!matchFlip(root, voyage, 0, voyage.size() - 1, flips)) {
            return { -1 };
        }
        return flips;
    }

    bool matchFlip(TreeNode *root, vector<int> &voyage, int i, int j, vector<int> &flips)  {
        if (root->left != nullptr && root->right != nullptr) {
            if (j - i < 2) return false;
            if (root->left->val == voyage[i + 1]) {
                for (int k = i + 2; k <= j; k++) {
                    if (voyage[k] == root->right->val) {
                        return matchFlip(root->left, voyage, i + 1, k - 1, flips) &&
                            matchFlip(root->right, voyage, k, j, flips);
                    }
                }
                return false;
            } else if (root->right->val == voyage[i + 1]) {
                flips.push_back(root->val);
                for (int k = i + 2; k <= j; k++) {
                    if (voyage[k] == root->left->val) {
                        return matchFlip(root->right, voyage, i + 1, k - 1, flips) &&
                            matchFlip(root->left, voyage, k, j, flips);
                    }
                }
                return false;
            } else {
                return false;
            }
        } else if (root->left != nullptr || root->right != nullptr) {
            if (j - i < 1) return false;
            auto child = root->left != nullptr ? root->left : root->right;
            if (child->val == voyage[i + 1]) {
                return matchFlip(child, voyage, i + 1, j, flips);
            } else {
                return false;
            }
        } else if (i != j) {
            return false;
        }

        return true;
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
        getline(cin, line);
        vector<int> voyage = stringToIntegerVector(line);

        vector<int> ret = Solution().flipMatchVoyage(root, voyage);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
