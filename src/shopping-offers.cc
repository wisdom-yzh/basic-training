#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int minPrice = std::numeric_limits<int>::max(), current = 0;
        recursionShoppingOffers(price, special, needs, current, minPrice);
        return minPrice;
    }

    void recursionShoppingOffers(vector<int> &price, vector<vector<int>> &special,
            vector<int> &needs, int &current, int &minPrice) {
        for (auto &s: special) {
            bool useThisSpecial = true;
            int minMount = std::numeric_limits<int>::max();
            for (int i = 0; i < s.size() - 1; i++) {
                if (needs[i] < s[i]) {
                    useThisSpecial = false;
                    break;
                }
                if (s[i] == 0) {
                    continue;
                }
                minMount = std::min(minMount, static_cast<int>(needs[i] / s[i]));
            }
            if (useThisSpecial) {
                pick(needs, s, minMount, current);
                this->recursionShoppingOffers(price, special, needs, current, minPrice);
                drop(needs, s, minMount, current);
            }
        }

        int restPrice = 0;
        for (int i = 0; i < price.size(); i++) {
            restPrice += price[i] * needs[i];
        }
        minPrice = std::min(current + restPrice, minPrice);
    }

    void pick(vector<int> &needs, vector<int> &s, int &mount, int &price) {
        for (int i = 0; i < needs.size(); i++) {
            needs[i] -= s[i] * mount;
        }
        price += s[s.size() - 1] * mount;
    }

    void drop(vector<int> &needs, vector<int> &s, int &mount, int &price) {
        for (int i = 0; i < needs.size(); i++) {
            needs[i] += s[i] * mount;
        }
        price -= s[s.size() - 1] * mount;
    }

};

int main() {
    vector<int> price { 2,5 };
    vector<vector<int>> special { {3,0,5}, {1,2,10} };
    vector<int> needs { 3,2 };
    cout << Solution().shoppingOffers(price, special, needs);
    return 0;
}
