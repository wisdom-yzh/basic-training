#include <iostream>
#include <sstream>
#include <algorithm>
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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    enum Position {
        Root = 0,
        Left,
        Right
    };

    vector<int> distanceK(TreeNode* root, int target, int K) {
        if (K == 0) {
            return vector<int> { target };
        }

        vector<int> arr;
        vector<TreeNode *> paths;
        this->dfsPath(paths, root, target);

        generate(arr, paths[paths.size() - 1], K);
        for (int i = paths.size() - 2; i >= 0; i--) {
            K--;
            if (K == 0) {
                arr.push_back(paths[i]->val);
                break;
            } else {
                generate(arr, paths[i]->right == paths[i + 1] ? paths[i]->left : paths[i]->right, K - 1);
            }
        }

        return arr;
    }

    bool dfsPath(vector<TreeNode*> &paths, TreeNode *root, int target) {
        if (root == nullptr) {
            return false;
        }
        if (root->val == target) {
            paths.push_back(root);
            return true;
        }

        paths.push_back(root);
        if (dfsPath(paths, root->left, target) || dfsPath(paths, root->right, target)) {
            return true;
        }
        paths.pop_back();
        return false;
    }

    void generate(vector<int> &arr, TreeNode *root, int height) {
        if (root == nullptr) {
            return;
        }
        if (height == 0) {
            arr.push_back(root->val);
            return;
        }
        this->generate(arr, root->left, height - 1);
        this->generate(arr, root->right, height - 1);
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

int stringToInteger(string input) {
    return stoi(input);
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
        int target = stringToInteger(line);
        getline(cin, line);
        int K = stringToInteger(line);

        vector<int> ret = Solution().distanceK(root, target, K);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
