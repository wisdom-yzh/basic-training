#include <vector>
#include <vector>
#include <stack>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> arr;
        recursionPostorder(arr, root);
        return arr;
    }

    void recursionPostorder(vector<int> &arr, Node *root) {
        if (root == nullptr) {
            return;
        }
        for (auto &child: root->children) {
            recursionPostorder(arr, child);
        }
        arr.push_back(root->val);
    }

    vector<int> noRecursionPostorder(Node *root) {
        vector<int> result;
        stack<Node *> stk;

        stk.push(root);
        while (!stk.empty()) {
            auto top = stk.top();
            stk.pop();
            if (top == nullptr) {
                continue;
            }

            result.insert(result.begin(), top->val);
            for (auto iter = top->children.begin(); iter != top->children.end(); iter++) {
                stk.push(*iter);
            }
        }

        return result;
    }
};

int main() {
    return 0;
}
