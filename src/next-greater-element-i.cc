#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::map<int, int> index2;
        for (int i = 0; i < nums2.size(); i++) {
            index2[nums2[i]] = i;
        }

        std::vector<int> result;
        for (int i = 0; i < nums1.size(); i++) {
            bool found = false;
            for (int j = index2[nums1[i]] + 1; j < nums2.size(); j++) {
                if (nums2[j] > nums1[i]) {
                    result.push_back(nums2[j]);
                    found = true;
                    break;
                }
            }
            if (!found) {
                result.push_back(-1);
            }
        }
        return result;
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);

        vector<int> ret = Solution().nextGreaterElement(nums1, nums2);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
