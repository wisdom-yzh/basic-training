#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 1) return "1";
        int nPermutation = 1;
        vector<int> arr;
        ostringstream oss;

        for (int i = 1; i <= n; i++) {
            nPermutation *= i;
            arr.push_back(i);
        }

        int permutation = nPermutation / n;
        while (n > 2) {
            size_t index = std::ceil(k / static_cast<double>(permutation)) - 1;
            oss << arr[index];
            arr.erase(arr.begin() + index);
            k -= index * permutation;
            n--;
            permutation /= n;
        }

        if (k == 2) oss << arr[1] << arr[0];
        else oss << arr[0] << arr[1];
        return oss.str();
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        string ret = Solution().getPermutation(n, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
