#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
using namespace std;

class Solution {
public:
    struct TrieNode {
        int val;
        shared_ptr<TrieNode> left, right;
        TrieNode(int x): val(x), left(nullptr), right(nullptr) {}
    };

    int findMaximumXOR(vector<int>& nums) {
        shared_ptr<TrieNode> root = make_shared<TrieNode>(0);

        // build trie
        auto curNode = root;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 31; j >= 0; j--) {
                int tmp = nums[i] & (1 << j);
                if (tmp == 0) {
                    if (!curNode->right) {
                        curNode->right = make_shared<TrieNode>(0);
                    }
                    curNode = curNode->right;
                } else {
                    if (!curNode->left) {
                        curNode->left = make_shared<TrieNode>(1);
                    }
                    curNode = curNode->left;
                }
            }
            curNode = root;
        }

        // calc
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            int res = 0;
            for (int j = 31; j >= 0; j--) {
                int tmp = nums[i] & (1 << j);
                if (curNode->left && curNode->right) {
                    if (tmp == 0) {
                        curNode = curNode->left;
                    } else {
                        curNode = curNode->right;
                    }
                } else {
                    curNode = curNode->left == nullptr ? curNode->right : curNode->left;
                }
                res += tmp ^ (curNode->val << j);
            }
            curNode = root;
            max = max > res ? max : res;
        }

        return max;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().findMaximumXOR(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
