#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        std::sort(A.begin(), A.end());

        for (int i = A.size() - 3; i >= 0; i--) {
            int maxIndex = 0;
            for (int j = i + 1; j < A.size() - 1 && maxIndex != -1; j++) {
                maxIndex = binarySearch(A, A[i] + A[j], j + 1);
                if (maxIndex != -1) {
                    return A[i] + A[j] + A[maxIndex];
                }
            }
        }

        return 0;
    }

    int binarySearch(vector<int> &A, int sum, int startIndex) {
        if (sum <= A[startIndex]) {
            return -1;
        }
        int left = startIndex, right = A.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (A[mid] < sum) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
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
        vector<int> A = stringToIntegerVector(line);

        int ret = Solution().largestPerimeter(A);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
