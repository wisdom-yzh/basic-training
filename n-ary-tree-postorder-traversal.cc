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
};

int main() {
    return 0;
}
