#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
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
  vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    int minDist = -1, maxDist = -1, distanceToFirst = -1, distanceToPrev = -1;

    if (head == nullptr) {
      return {minDist, maxDist};
    }

    ListNode *prev = head, *current = head->next, *next = current->next;
    while (next != nullptr) {
      if (distanceToPrev != -1) {
        distanceToFirst++;
        distanceToPrev++;
      }

      if (current->val > prev->val && current->val > next->val ||
          current->val < prev->val && current->val < next->val) {
        if (distanceToPrev == -1) {
          distanceToFirst = distanceToPrev = 0;
        } else {
          if (minDist == -1) {
            minDist = distanceToPrev;
          } else {
            minDist = std::min(minDist, distanceToPrev);
          }
          distanceToPrev = 0;

          maxDist = distanceToFirst;
        }
      }

      prev = current;
      current = next;
      next = next->next;
    }

    return {minDist, maxDist};
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

string integerVectorToString(vector<int> list, int length = -1) {
  if (length == -1) {
    length = list.size();
  }

  if (length == 0) {
    return "[]";
  }

  string result;
  for (int index = 0; index < length; index++) {
    int number = list[index];
    result += to_string(number) + ", ";
  }
  return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
  string line;
  while (getline(cin, line)) {
    ListNode *head = stringToListNode(line);

    vector<int> ret = Solution().nodesBetweenCriticalPoints(head);

    string out = integerVectorToString(ret);
    cout << out << endl;
  }
  return 0;
}
