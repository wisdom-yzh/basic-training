#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countArrangement(int N) {
        std::vector<int> vec(N, 0);
        for (int i = 1; i <= N; i++) {
            vec[i - 1] = i;
        }
        return this->countRecursion(N, vec);
    }

    int countRecursion(int n, vector<int> &vec) {
        if (n <= 0) {
            return 1;
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (vec[i] % n == 0 || n % vec[i] == 0) {
                std::swap(vec[i], vec[n - 1]);
                result += this->countRecursion(n - 1, vec);
                std::swap(vec[i], vec[n - 1]);
            }
        }
        return result;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);

        int ret = Solution().countArrangement(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
