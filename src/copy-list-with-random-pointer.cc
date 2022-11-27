#include <iostream>
#include <map>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        RandomListNode *newHead = new RandomListNode(head->label);
        std::map<RandomListNode *, RandomListNode *> t;
        t.emplace(head, newHead);
        RandomListNode *p = head, *q = newHead;

        for (size_t i = 1; p->next != nullptr; i++) {
            p = p->next;
            RandomListNode *newNode = new RandomListNode(p->label);
            q->next = newNode;
            q = q->next;
            t.emplace(p, q);
        }

        p = head, q = newHead;
        while (p != nullptr) {
            if (p->random != nullptr) {
                q->random = t[p->random];
            }
            p = p->next;
            q = q->next;
        }

        return newHead;
    }
};

int main() {
    return 0;
}
