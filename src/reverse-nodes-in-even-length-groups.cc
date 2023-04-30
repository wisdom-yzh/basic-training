#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
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
  ListNode *reverseEvenLengthGroups(ListNode *head) {
    int groupCount = 1, count = 0;
    ListNode *p = head, *prevP = nullptr;
    ListNode *prevGroupHead = nullptr, *afterGroupTail = nullptr;

    while (p != nullptr) {
      count++;

      if (count == groupCount) {
        afterGroupTail = p->next;
        prevP = p;
        p = p->next;

        if ((groupCount % 2) == 0) {
          ListNode *nextPrevGroupHead = prevGroupHead->next;
          reverseList(prevGroupHead, afterGroupTail);
          prevGroupHead = nextPrevGroupHead;
        } else {
          prevGroupHead = prevP;
        }
        count = 0;
        groupCount++;
        continue;
      }

      prevP = p;
      p = p->next;
    }

    if (count > 0 && (count % 2) == 0) {
      reverseList(prevGroupHead, nullptr);
    }

    return head;
  }

  void reverseList(ListNode *preHead, ListNode *afterTail) {
    ListNode *p = preHead->next, *q = p->next, *r = q->next;
    p->next = afterTail;

    while (true) {
      q->next = p;
      if (r == afterTail) {
        break;
      }
      p = q;
      q = r;
      r = r->next;
    }

    preHead->next = q;
  }
};

void trimLeftTrailingSpaces(string &input) {
  input.erase(input.begin(), find_if(input.begin(), input.end(),
                                     [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input) {
  input.erase(
      find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); })
          .base(),
      input.end());
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

ListNode *stringToListNode(string input) {
  // Generate list from the input
  vector<int> list = stringToIntegerVector(input);

  // Now convert that list into linked list
  ListNode *dummyRoot = new ListNode(0);
  ListNode *ptr = dummyRoot;
  for (int item : list) {
    ptr->next = new ListNode(item);
    ptr = ptr->next;
  }
  ptr = dummyRoot->next;
  delete dummyRoot;
  return ptr;
}

string listNodeToString(ListNode *node) {
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
    ListNode *head = stringToListNode(line);

    ListNode *ret = Solution().reverseEvenLengthGroups(head);

    string out = listNodeToString(ret);
    cout << out << endl;
  }
  return 0;
}
