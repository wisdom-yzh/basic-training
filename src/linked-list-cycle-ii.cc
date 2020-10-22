#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode *p1 = head, *p2 = head;
        do {
            p1 = p1->next;
            p2 = p2->next;
            if (p2 == nullptr) {
                break;
            }
            p2 = p2->next;
        }
        while (p1 != p2 && p1 != nullptr && p2 != nullptr);
        if (p1 == nullptr || p2 == nullptr) {
            return nullptr;
        }
        ListNode *p = head;
        while (p != p1) {
            p = p->next;
            p1 = p1->next;
        }
        return p;
    }
};

int main() {
    ListNode *p = new ListNode(1);
    p->next = new ListNode(2);
    cout << Solution().detectCycle(p);
    return 0;
}
