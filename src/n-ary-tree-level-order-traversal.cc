#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if (root == nullptr) {
            return ret;
        }

        queue<pair<int, Node *>> q;

        q.emplace(make_pair(0, root));
        while (!q.empty()) {
            auto front = q.front();
            int level = front.first;
            Node *p = front.second;

            if (ret.size() == level) {
                ret.emplace_back(vector<int> { p->val });
            } else {
                ret[level].push_back(p->val);
            }

            for (Node *& child: p->children) {
                q.emplace(make_pair(level + 1, child));
            }
            q.pop();
        }

        return ret;
    }
};

int main() {
    return 0;
}
