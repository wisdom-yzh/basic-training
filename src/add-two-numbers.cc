#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *next = nullptr) : val(x), next(next) {}
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        }

        ListNode *l = l1, *p = l;
        int addOne = 0, total = 0;
        while (true) {
            total = 0;
            if (l1) {
                total += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                total += l2->val;
                l2 = l2->next;
            }
            total += addOne;

            if (total >= 10) {
                total -= 10;
                addOne = 1;
            } else {
                addOne = 0;
            }
            p->val = total;

            if (l1) {
                p->next = l1;
                p = p->next;
            } else if (l2) {
                p->next = l2;
                p = p->next;
            } else {
                if (addOne) {
                    p->next = new ListNode(addOne);
                }
                break;
            }
        }

        return l;
    }
};

int main() {
    Solution solution;

//    ListNode *l = solution.addTwoNumbers(
//        new ListNode(2, new ListNode(4, new ListNode(3))),
//        new ListNode(5, new ListNode(6, new ListNode(4)))
//    );
//    while (l) {
//        std::cout << l->val;
//        l = l->next;
//    }
//
//    l = solution.addTwoNumbers(
//        new ListNode(2),
//        new ListNode(0)
//    );
//    while (l) {
//        std::cout << l->val;
//        l = l->next;
//    }

    ListNode *l = solution.addTwoNumbers(
        new ListNode(0),
        new ListNode(7, new ListNode(3))
    );
    while (l) {
        std::cout << l->val;
        l = l->next;
    }

    return 0;
}
