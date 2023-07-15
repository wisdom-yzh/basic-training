#include <bits/stdc++.h>
#include <cassert>
#include <string>

class Bitset {
public:
  Bitset(int size) : arr(size, '0'), oneCount(0), reversed(false) {}

  void fix(int idx) {
    if (reversed && arr[idx] == '1') {
      arr[idx] = '0';
      oneCount--;
      return;
    }

    if (!reversed && arr[idx] == '0') {
      arr[idx] = '1';
      oneCount++;
      return;
    }
  }

  void unfix(int idx) {
    if (reversed && arr[idx] == '0') {
      arr[idx] = '1';
      oneCount++;
      return;
    }

    if (!reversed && arr[idx] == '1') {
      arr[idx] = '0';
      oneCount--;
      return;
    }
  }

  void flip() { reversed = !reversed; }

  bool all() { return reversed ? oneCount == 0 : oneCount == arr.size(); }

  bool one() { return reversed ? oneCount < arr.size() : oneCount > 0; }

  int count() { return reversed ? arr.size() - oneCount : oneCount; }

  std::string toString() {
    if (!reversed) {
      return arr;
    }
    std::string res(arr);
    for (auto &ch : res) {
      ch = ch == '1' ? '0' : '1';
    }
    return res;
  }

private:
  std::string arr;
  int oneCount;
  bool reversed;
};

/**
 * Your Bitset object will be instantiated and called as such:
 */
int main(int argc, char *argv[]) {
  Bitset bs(5);
  bs.fix(3); // the value at idx = 3 is updated to 1, so bitset = "00010".
  bs.fix(1); // the value at idx = 1 is updated to 1, so bitset = "01010".
  bs.flip(); // the value of each bit is flipped, so bitset = "10101".
  assert(!bs.all()); // return False, as not all values of the bitset are 1.
  bs.unfix(0); // the value at idx = 0 is updated to 0, so bitset = "00101".
  bs.flip();   // the value of each bit is flipped, so bitset = "11010".
  assert(bs.one()); // return True, as there is at least 1 index with value 1.
  bs.unfix(0); // the value at idx = 0 is updated to 0, so bitset = "01010".
  assert(bs.count() == 2); // return 2, as there are 2 bits with value 1.
  assert(bs.toString() ==
         "01010"); // return "01010", which is the composition of bitset.
  return 0;
}
