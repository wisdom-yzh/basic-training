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
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        int result = 0;
        for (auto *p: root->children) {
            result = std::max(result, maxDepth(p));
        }

        return result + 1;
    }
};

int main() {
    return 0;
}
