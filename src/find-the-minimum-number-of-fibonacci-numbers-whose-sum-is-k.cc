#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<uint32_t> arr;
        arr.push_back(1);
        arr.push_back(1);

        while (arr.back() < k) {
            arr.push_back(arr[arr.size() - 1] + arr[arr.size() - 2]);
        }

        int res = 0;
        for (int i = arr.size() - 1; i >= 0;) {
            if (arr[i] > k) {
                i--;
            } else if (arr[i] == k) {
                res++;
                break;
            } else {
                res++;
                k -= arr[i];
            }
        }

        return res;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int k = stringToInteger(line);

        int ret = Solution().findMinFibonacciNumbers(k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
