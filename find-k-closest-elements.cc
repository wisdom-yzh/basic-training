#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int mid = findClosestIndex(arr, x);
        return expandElementRange(arr, mid, k, x);
    }

    int findClosestIndex(vector<int> &arr, int x) {
        int left = 0, right = arr.size() - 1, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (arr[mid] < x) {
                if (mid + 1 == right || arr[mid + 1] > x) {
                    mid = mid + 1;
                    break;
                } else {
                    left = mid + 1;
                }
            } else if (arr[mid] > x) {
                if (left == mid || arr[mid - 1] < x) {
                    break;
                } else {
                    right = mid - 1;
                }
            } else if (arr[mid] == x) {
                break;
            }
        }
        if (mid > 0 && std::abs(arr[mid - 1] - x) < std::abs(arr[mid] - x)) {
            mid--;
        }
        return mid;
    }

    vector<int> expandElementRange(vector<int> &arr, int mid, int k, int x) {
        int left = mid - 1, right = mid + 1;
        for (int m = k - 1; m > 0; m--) {
            if (left < 0) {
                right++;
            } else if (right >= arr.size()) {
                left--;
            } else if (std::abs(arr[left] - x) > std::abs(arr[right] - x)) {
                right++;
            } else {
                left--;
            }
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
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

int stringToInteger(string input) {
    return stoi(input);
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
        vector<int> arr = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        getline(cin, line);
        int x = stringToInteger(line);

        vector<int> ret = Solution().findClosestElements(arr, k, x);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
