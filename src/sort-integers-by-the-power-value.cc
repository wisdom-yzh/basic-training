#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<int, int> memo;

    int getKth(int lo, int hi, int k) {
        std::unordered_map<int, int> dict;

        for (int i = lo; i <= hi; i++) {
            dict.emplace(i, getRank(i));
        }

        std::vector<pair<int, int>> data;
        for (auto &p: dict) {
            data.push_back(p);
        }

        std::sort(data.begin(), data.end(), [](pair<int, int> &a, pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        });

        return data[k - 1].first;
    }

    int getRank(int n) {
        if (n == 1) {
            memo[1] = 0;
            return 0;
        }

        auto iter = memo.find(n);
        if (iter != memo.end()) {
            return iter->second;
        }

        int res = 1;
        if ((n % 2) == 0) {
            res += getRank(n / 2);
        } else {
            res += getRank(3 * n + 1);
        }

        memo.emplace(n, res);
        return res;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int lo = stringToInteger(line);
        getline(cin, line);
        int hi = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);

        int ret = Solution().getKth(lo, hi, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
