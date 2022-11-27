#include <iostream>
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
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode *p1 = head, *p2 = head->next->next;
        while (p1 != p2 && p1 != nullptr && p2 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
            if (p2 == nullptr) {
                break;
            }
            p2 = p2->next;
        }
        if (p1 == nullptr || p2 == nullptr) {
            return false;
        }
        return true;
    }
};

int main() {
    return 0;
}
