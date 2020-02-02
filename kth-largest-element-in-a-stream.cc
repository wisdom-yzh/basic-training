#include <vector>
#include <algorithm>
#include <cassert>
#include <functional>
using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums): nums(std::move(nums)), k(k) {
        std::sort(this->nums.begin(), this->nums.end(), std::greater<int>());
    }

    int add(int val) {
        auto iter = this->nums.begin();
        while (iter != this->nums.end()) {
            if (*iter < val) {
                break;
            }
            iter++;
        }

        if (iter == nums.end()) {
            this->nums.push_back(val);
        } else {
            this->nums.insert(iter, val);
        }
        return this->nums[k - 1];
    }

private:
    vector<int> nums;
    int k;
};

int main() {
    vector<int> nums { 4,5,8,2 };
    KthLargest obj(3, nums);

    assert(obj.add(1) == 4);
    assert(obj.add(3) == 4);
    assert(obj.add(5) == 5);
    assert(obj.add(10) == 5);
    assert(obj.add(9) == 8);
    assert(obj.add(4) == 8);
    return 0;
}
