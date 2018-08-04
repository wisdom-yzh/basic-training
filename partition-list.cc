#include <iostream>
#include <sstream>
#include <vector>
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *frontHead = nullptr;
        ListNode *frontTail = nullptr;
        ListNode *backHead = nullptr;
        ListNode *backTail = nullptr;

        while (head != nullptr) {
            int value = head->val;
            ListNode *current = head;
            head = head->next;

            if (value < x) {
                if (frontHead == nullptr) {
                    frontHead = frontTail = current;
                } else {
                    frontTail->next = current;
                    frontTail = frontTail->next;
                }
                frontTail->next = nullptr;
            } else {
                if (backHead == nullptr) {
                    backHead = backTail = current;
                } else {
                    backTail->next = current;
                    backTail = backTail->next;
                }
                backTail->next = nullptr;
            }
        }
        if (frontTail != nullptr) {
            frontTail->next = backHead;
        }

        return frontHead == nullptr ? backHead : frontHead;
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

int stringToInteger(string input) {
    return stoi(input);
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
        getline(cin, line);
        int x = stringToInteger(line);
        ListNode* ret = Solution().partition(head, x);
        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
