#include <cstdlib>
#include <ctime>
#include <stdio.h>

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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head = nullptr) {
        std::srand(std::time(nullptr));
        this->head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        int index = 2;
        int result = head->val;
        auto *p = head->next;
        while (p != nullptr) {
            int random = rand() % index;
            if (random == 0) {
                result = p->val;
            }
            index++;
            p = p->next;
        }
        return result;
    }

private:
    ListNode *head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
int main() {
    Solution obj;
    return obj.getRandom();
}
