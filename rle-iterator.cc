#include <vector>
#include <iostream>
using namespace std;

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
class RLEIterator {
public:
    RLEIterator(vector<int>& A): vec(A), index(1), number(0), end(false) {
        if (!A.empty()) {
            number = A[index - 1];
        }
    }

    int next(int n) {
        if (end) {
            return -1;
        }
        while (n > number) {
            n -= number;
            index += 2;
            if (index >= vec.size()) {
                end = true;
                return -1;
            }
            number = vec[index - 1];
        }

        number -= n;
        return vec[index];
    }

private:
    vector<int> vec;
    int index;
    int number;
    bool end;
};

int main() {
    vector<int> vec { 635,606,576,391,370,981,36,21,961,185,124,210,801,937,22,426,101,260,221,647,350,180,504,39,101,989,199,358,732,839,919,169,673,967,58,676,846,342,250,597,442,174,472,410,569,509,311,357,838,251 };
    vector<int> nextQueue { 5039,62,3640,671,67,395,262,839,74,43,42,77,13,6,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
    RLEIterator rle(vec);
    for (const auto &n: nextQueue) {
        cout << rle.next(n) << endl;
    }
    return 0;
}
