#include <iostream>
using namespace std;

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        auto *p = new Node(true, true, nullptr, nullptr, nullptr, nullptr);
        if ((quadTree1->isLeaf && quadTree1->val) ||
            (quadTree2->isLeaf && !quadTree2->val)) {
            return quadTree1;
        }
        if ((quadTree2->isLeaf && quadTree2->val) ||
            (quadTree1->isLeaf && !quadTree1->val)) {
            return quadTree2;
        }

        p->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        p->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        p->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        p->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);

        if (p->bottomLeft->isLeaf &&
            p->bottomRight->isLeaf &&
            p->topLeft->isLeaf &&
            p->topRight->isLeaf &&
            p->bottomLeft->val == p->bottomRight->val &&
            p->bottomRight->val == p->topLeft->val &&
            p->topLeft->val == p->topRight->val) {
            p->isLeaf = true;
            p->val = p->topLeft->val;
            p->topLeft = p->topRight = p->bottomLeft = p->bottomRight = nullptr;
        } else {
            p->isLeaf = false;
            p->val = false;
        }

        return p;
    }
};

int main() {
    return 0;
}
