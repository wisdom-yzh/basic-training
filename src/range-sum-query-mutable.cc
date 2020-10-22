#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
        if (nums.empty()) {
            return;
        }
        this->root = this->buildSegmentTree(nums, 0, nums.size() - 1);
    }
    
    void update(int i, int val) {
        this->modifySegmentTree(i, val, this->root);
    }
    
    int sumRange(int i, int j) {
        return this->querySegmentTree(i, j, this->root);
    }

private:
    typedef struct SegmentTreeNode {
        shared_ptr<SegmentTreeNode> left, right;
        size_t start, end;
        int sum;
    } SegmentTreeNode;

    shared_ptr<SegmentTreeNode> buildSegmentTree(vector<int> &nums, size_t start, size_t end) {
        shared_ptr<SegmentTreeNode> r = make_shared<SegmentTreeNode>();
        if (start == end) {
            r->start = r->end = start;
            r->left = r->right = nullptr;
            r->sum = nums[start];
            return r;
        }
        size_t mid = start + (end - start) / 2;
        r->left = buildSegmentTree(nums, start, mid);
        r->right = buildSegmentTree(nums, mid + 1, end);
        r->start = start;
        r->end = end;
        r->sum = r->left->sum + r->right->sum;
        return r;
    }

    int modifySegmentTree(size_t i, int val, shared_ptr<SegmentTreeNode> &r) {
        if (r == nullptr) {
            return 0;
        }
        int diff;
        if (r->start == i && r->end == i) {
            diff = val - r->sum;
            r->sum = val;
            return diff;
        }
        size_t mid = r->start + (r->end - r->start) / 2;
        if (mid < i) {
            diff = modifySegmentTree(i, val, r->right);
        } else {
            diff = modifySegmentTree(i, val, r->left);
        }
        r->sum += diff;
        return diff;
    }

    int querySegmentTree(size_t start, size_t end, shared_ptr<SegmentTreeNode> &r) {
        if (r == nullptr) {
            return 0;
        }
        if (start == r->start && end == r->end) {
            return r->sum;
        }
        size_t mid = r->start + (r->end - r->start) / 2;
        if (end <= mid) {
            return this->querySegmentTree(start, end, r->left);
        } else if (start >= mid + 1) {
            return this->querySegmentTree(start, end, r->right);
        } else {
            return this->querySegmentTree(start, mid, r->left) +
                this->querySegmentTree(mid + 1, end, r->right);
        }
    }

    shared_ptr<SegmentTreeNode> root;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
int main() {
    NumArray numArray(vector<int>({ 1, 3, 5 }));
    cout << numArray.sumRange(0, 2);
    numArray.update(1, 2);
    cout << numArray.sumRange(0, 2);
    return 0;
}
