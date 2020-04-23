#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode *> result;

        int length = 0;
        auto p = root;
        while (p != nullptr) {
            length++;
            p = p->next;
        }

        int mod = length % k;
        int elemSize = length / k;
        
        p = root;
        for (int i = 0; i < mod; i++) {
            split(p, result, elemSize + 1);
        }
        for (int i = mod; i < k ; i++) {
            split(p, result, elemSize);
        }

        return result;
    }

    void split(ListNode *&root, vector<ListNode *> &arr, int size) {
        if (size == 0) {
            arr.push_back(nullptr);
            return;
        }
        arr.push_back(root);
        
        auto p = root;
        for (int i = 0; i < size - 1; i++) {
            p = p->next;
        }
        
        if (p->next != nullptr) {
            root = p->next;
            p->next = nullptr; 
        }
    }
};

int main() {
    return 0;
}
