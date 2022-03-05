#include <functional>
#include <limits>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        std::sort(baseCosts.begin(), baseCosts.end(), std::greater<int>());
        std::sort(toppingCosts.begin(), toppingCosts.end(), std::greater<int>());

        vector<int> flatToppingCosts(toppingCosts.size() * 2);
        for (int i = 0; i < toppingCosts.size(); i++) {
            int j = i * 2;
            flatToppingCosts[j] = flatToppingCosts[j + 1] = toppingCosts[i];
        }

        int res = std::numeric_limits<int>::max();
        for (auto &base: baseCosts) {
            int tmp = dfs(target - base, flatToppingCosts, 0);
            if (abs(res) == abs(tmp)) {
                res = std::max(res, tmp);
            } else {
                res = abs(res) < abs(tmp) ? res : tmp;
            }
        }
        return target - res ;
    }
    
    int dfs(int price, vector<int> &costs, int idx) {
        if (price <= 0 || idx == costs.size()) {
            return price;
        }

        int use = dfs(price, costs, idx + 1);
        int ignore = dfs(price - costs[idx], costs, idx + 1);
        if (abs(use) == abs(ignore)) {
            return std::max(use, ignore);
        } else {
            return abs(use) < abs(ignore) ? use : ignore;
        }
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> baseCosts = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> toppingCosts = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        int ret = Solution().closestCost(baseCosts, toppingCosts, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
