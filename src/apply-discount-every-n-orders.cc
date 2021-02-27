#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Cashier {
public:
    int n, discount, cnt;
    map<int, int> menu;

    Cashier(int n, int discount, vector<int>& products, vector<int>& prices):
        n(n), discount(discount), cnt(0) {
        for (int i = 0; i < products.size(); i++) {
            menu.emplace(products[i], prices[i]);
        }
    }

    double getBill(vector<int> product, vector<int> amount) {
        cnt++;
        double res = 0;
        for (int i = 0; i < product.size(); i++) {
            res += menu[product[i]] * amount[i];
        }
        if (cnt % n == 0) {
            res = res - (discount * res) / 100;
        }
        return res;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 */
int main() {
    vector<int> products {1,2,3,4,5,6,7};
    vector<int> prices {100,200,300,400,300,200,100};
    vector<vector<vector<int>>> testCases {
        {{1,2},{1,2}},
        {{3,7},{10,10}},
        {{1,2,3,4,5,6,7},
        {1,1,1,1,1,1,1}},
        {{4},
        {10}},
        {{7,3},
        {10,10}},
        {{7,5,3,1,6,4,2},
        {10,10,10,9,9,9,7}},
        {{2,3,5}, {5,3,2}}
    };

    Cashier obj(3, 50, products, prices);
    for (auto &testCase: testCases) {
        cout << obj.getBill(testCase[0], testCase[1]) << endl;
    }
    return 0;
}
