#include <iostream>
#include <cmath>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        int sizeA = 0, sizeB = 0;
        ListNode *p = headA;
        while (p != nullptr) {
            sizeA++;
            p = p->next;
        }
        p = headB;
        while (p != nullptr) {
            sizeB++;
            p = p->next;
        }
        int diffLength = abs(sizeA - sizeB);
        ListNode *p1, *p2; // p1 short p2 long
        if (sizeA > sizeB) {
            p1 = headB;
            p2 = headA;
        } else {
            p1 = headA;
            p2 = headB;
        }
        for (int i = 0; i < diffLength; i++) {
            p2 = p2->next;
        }
        while (p1 != nullptr && p2 != nullptr && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};

int main() {
    return 0;
}
