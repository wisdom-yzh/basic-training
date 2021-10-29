#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <memory>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto prev = std::unique_ptr<ListNode>(new ListNode {0, list1});
        auto p = prev.get();

        for (int i = 0; i < a; i++) {
            p = p->next;
        }

        auto q = p->next;
        for (int i = a; i < b; i++) {
            q = q->next;
        }

        p->next = list2;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = q->next;
        return prev->next;
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
        ListNode* list1 = stringToListNode(line);
        getline(cin, line);
        int a = stringToInteger(line);
        getline(cin, line);
        int b = stringToInteger(line);
        getline(cin, line);
        ListNode* list2 = stringToListNode(line);

        ListNode* ret = Solution().mergeInBetween(list1, a, b, list2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
