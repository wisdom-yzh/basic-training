#include <vector>
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
};

int main() {
    return 0;
}
