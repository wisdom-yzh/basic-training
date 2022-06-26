#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class FindSumPairs {
public:
  vector<int> vec1, vec2;
  unordered_map<int, int> dict;

  FindSumPairs(vector<int> &nums1, vector<int> &nums2)
      : vec1(nums1), vec2(nums2) {
    for (auto &num : nums2) {
      dict[num]++;
    }
  }

  void add(int index, int val) {
    auto &x = vec2[index];
    dict[x + val]++;
    dict[x]--;
    vec2[index] += val;
  }

  int count(int tot) {
    int res = 0;
    for (auto &x : vec1) {
      res += dict[tot - x];
    }
    return res;
  }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
int main() {
  auto nums1{vector<int>{1, 1, 2, 2, 2, 3}};
  auto nums2{vector<int>{1, 4, 5, 2, 5, 4}};
  auto obj = FindSumPairs(nums1, nums2);

  return 0;
}
