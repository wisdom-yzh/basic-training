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
    vector<int> preorder(Node* root) {
        vector<int> arr;
        recursionPreorder(arr, root);
        return arr;
    }

    void recursionPreorder(vector<int> &arr, Node *root) {
        if (root == nullptr) {
            return;
        }
        arr.push_back(root->val);
        for (auto &child: root->children) {
            recursionPreorder(arr, child);
        }
    }

    vector<int> noRecursionPreorder(Node *root) {
        stack<Node *> stk;
        vector<int> result;

        stk.push(root);
        while (!stk.empty()) {
            Node *p = stk.top();
            stk.pop();
            if (p == nullptr) {
                continue;
            }
            for (auto iter = p->children.rbegin(); iter != p->children.rend(); iter++) {
                stk.push(*iter);
            }
            result.push_back(p->val);
        }
        return result;
    }
};

int main() {
    return 0;
}
