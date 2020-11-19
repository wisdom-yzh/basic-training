#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        while (true) {
            vector<ListNode *> tmp;
            vector<int> sums;

            auto *p = head;
            int index = 0;
            int start = -1, end = -1;

            while (p != nullptr && start == -1 && end == -1) {
                if (p->val == 0) {
                    start = end = index;
                } else {
                    for (int i = 0; i < sums.size(); i++) {
                        sums[i] += p->val;
                        if (sums[i] == 0) {
                            start = i;
                            end = index;
                        }
                    }
                }

                sums.push_back(p->val);
                tmp.push_back(p);
                p = p->next;
                index++;
            }

            if (start == -1 && end == -1) {
                return head;
            }

            if (start == 0) {
                head = tmp[end]->next;
            } else {
                tmp[start - 1]->next = tmp[end]->next;
            }
        }
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
    vector<int> list = stringToIntegerVector(input);

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

        ListNode* ret = Solution().removeZeroSumSublists(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
