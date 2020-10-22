#include <stack>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node *> s;
        Node *pNewHead = nullptr, *pCurrent, *p = head;
        
        while (p) {
            if (!pNewHead) {
                pCurrent = pNewHead = p;
            } else {
                pCurrent->next = p;
                p->prev = pCurrent;
                pCurrent = pCurrent->next;
            }

            if (p->child) {
                if (p->next) {
                    s.push(p->next);
                }
                p = p->child;
            } else if (p->next) {
                p = p->next;
            } else if (!s.empty()) {
                p = s.top();
                s.pop();
            } else {
                p = nullptr;
            }
        }

        for (p = pNewHead; p != nullptr; p = p->next) {
            p->child = nullptr;
        }

        return pNewHead;
    }
};

int main() {
    return 0;
}
