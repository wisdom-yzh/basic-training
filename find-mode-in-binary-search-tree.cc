#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
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
    vector<int> findMode(TreeNode* root) {
        mode.clear();
        modeCount = 0;
        if (!root) {
            return vector<int>(0);
        }
        iterate(root);
        updateMode();
        return mode;
    }

    void handler(int val) {
        if (seriesNum == 0) {
            prev = val;
            seriesNum++;
        } else if (val == prev) {
            seriesNum++;
        } else {
            updateMode();
            seriesNum = 1;
            prev = val;
        }
    }

    void updateMode() {
        if (seriesNum > modeCount) {
            mode.clear();
            mode.push_back(prev);
            modeCount = seriesNum;
            return;
        }
        if (seriesNum == modeCount) {
            mode.push_back(prev);
        }
    }

    void iterate(TreeNode *root) {
        if (root->left) {
            iterate(root->left);
        }
        handler(root->val);
        if (root->right) {
            iterate(root->right);
        }
    }

private:
    int prev, seriesNum;
    int modeCount;
    vector<int> mode;
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

        vector<int> ret = Solution().findMode(root);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
