#include <iostream>
#include <sstream>
#include <queue>
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
    // 由于是使用C++语言，提交后，测试案例测试完成之后会对链表进行析构删除
    // 所以需要保证链表内部不能有环!!!!!!!
    // 否则会出现超时的情况
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            fast = fast->next;
            if (fast) {
                fast = fast->next;
            }
            slow = slow->next;
        }
        ListNode *p = slow, *q = slow->next, *r;
        while (q != nullptr) {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        slow->next = nullptr;
        q = head;
        while (true) {
            if (p->val != q->val) {
                return false;
            }
            if (p == slow) {
                break;
            }
            p = p->next;
            q = q->next;
        }
        return true;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        
        bool ret = Solution().isPalindrome(head);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
