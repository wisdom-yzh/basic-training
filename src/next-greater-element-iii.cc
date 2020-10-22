#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        auto arr = splitNumber(n);
        int left = -1, right = -1, p = 0;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[p] < arr[i]) {
                left = p;
                right = i;
            } else if (right != -1 && arr[i] <= arr[right] && arr[i] > arr[left]) {
                right = i;
            }
            p = i;
        }

        if (right == -1) {
            return -1;
        }

        std::swap(arr[left], arr[right]);
        std::sort(arr.begin() + left + 1, arr.end(), std::less<int>());

        int64_t result = 0;
        for (auto iter = arr.begin(); iter != arr.end(); iter++) {
            result = result + *iter;
            if (iter != arr.end() - 1) {
                result *= 10;
            }
        }

        if (result > std::numeric_limits<int32_t>::max()) {
            return -1;
        }
        return result;
    }

    vector<int> splitNumber(int n) {
        vector<int> arr;
        while (n != 0) {
            arr.push_back(n % 10);
            n /= 10;
        }

        std::reverse(arr.begin(), arr.end());
        return arr;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().nextGreaterElement(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
