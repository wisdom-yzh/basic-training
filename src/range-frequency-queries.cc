#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <vector>
using namespace std;

class RangeFreqQuery {
public:
  RangeFreqQuery(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
      dict_[arr[i]].push_back(i);
    }
  }

  int query(int left, int right, int value) {
    auto &arr = dict_[value];
    auto t1 = std::upper_bound(arr.begin(), arr.end(), left - 1);
    auto t2 = std::upper_bound(arr.begin(), arr.end(), right);
    return t2 - t1;
  }

private:
  std::unordered_map<int, vector<int>> dict_;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
int main(int argc, char *argv[]) {
  std::vector<int> arr{12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56};
  RangeFreqQuery obj(arr);

  assert(obj.query(1, 2, 4) == 1);
  assert(obj.query(0, 11, 33) == 2);

  return 0;
}
