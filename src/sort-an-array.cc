#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        qsort(nums, 0, nums.size() - 1);
        return nums;
    }

    void qsort(vector<int> &arr, int p, int q) {
        if (p >= q) {
            return;
        }
        int mid = partition(arr, p, q);
        qsort(arr, p, mid - 1);
        qsort(arr, mid + 1, q);
    }

    int partition(vector<int> &arr, int p, int q) {
        int num = arr[p], mid = p;
        for (int i = p + 1; i <= q; i++) {
            if (arr[i] < num) {
                mid++;
                swap(arr[mid], arr[i]);
            }
        }

        std::swap(arr[p], arr[mid]);
        return mid;
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
        vector<int> nums = stringToIntegerVector(line);

        vector<int> ret = Solution().sortArray(nums);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
