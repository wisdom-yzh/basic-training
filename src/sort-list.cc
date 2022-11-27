#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
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
    // 超时的快排
    ListNode* recursionSortList(ListNode *head, ListNode *tail) {
        if (head == tail || head->next == tail) {
            return head;
        }

        ListNode *partition = head;
        ListNode *p = partition->next;
        while (p != tail) {
            if (p->val < head->val) {
                std::swap(partition->next->val, p->val);
                partition = partition->next;
            }
            p = p->next;
        }

        std::swap(partition->val, head->val);
        this->recursionSortList(head, partition);
        this->recursionSortList(partition->next, nullptr);
        return head;
    }

    // 归并排序
    ListNode* merge(ListNode* head1 , ListNode * head2) {
        ListNode* d = new ListNode (0);            // dummy node
        ListNode* e = d;
        while (head1 || head2) {
            if (head1 && (!head2 || head1->val <= head2-> val)) {
                e=e->next= head1 ;
                head1 = head1 -> next;
            }
            if (head2 && (!head1 || head2->val < head1 -> val)) {
                e = e->next = head2 ;
                head2 = head2 -> next;
            }
        }
        e->next = nullptr;
        return d->next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast =head->next;
        while (fast && fast->next) {         // to find middle node
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* headb = slow->next;     // headb is start of 2nd half of list
        slow->next = nullptr;
        return merge(sortList(head) , sortList(headb));
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);

        ListNode* ret = Solution().sortList(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
