#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

class ProductOfNumbers {
public:
    vector<uint32_t> arr;

    ProductOfNumbers() {

    }

    void add(int num) {
        if (num == 0) {
            arr.clear();
            return;
        }

        if (arr.empty()) {
            arr.push_back(num);
        } else {
            arr.push_back(arr.back() * num);
        }
    }

    int getProduct(int k) {
        if (k > arr.size()) {
            return 0;
        } else if (k == arr.size()) {
            return arr.back();
        }
        return arr.back() / arr[arr.size() - 1 - k];
    }
};

int main() {
    ProductOfNumbers productOfNumbers;
    productOfNumbers.add(3);        // [3]
    productOfNumbers.add(0);        // [3,0]
    productOfNumbers.add(2);        // [3,0,2]
    productOfNumbers.add(5);        // [3,0,2,5]
    productOfNumbers.add(4);        // [3,0,2,5,4]
    cout << productOfNumbers.getProduct(2) << endl; // return 20. The product of the last 2 numbers is 5 * 4 = 20
    cout << productOfNumbers.getProduct(3) << endl; // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
    cout << productOfNumbers.getProduct(4) << endl; // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
    productOfNumbers.add(8);        // [3,0,2,5,4,8]
    cout << productOfNumbers.getProduct(2) << endl; // return 32. The product of the last 2 numbers is 4 * 8 = 32
    return 0;
}
