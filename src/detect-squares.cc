#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class DetectSquares {
public:
  DetectSquares() {}

  void add(vector<int> point) { map_[point[1]][point[0]]++; }

  int count(vector<int> point) {
    int res = 0;
    int x = point[0], y = point[1];

    auto py = map_.find(y);
    if (py == map_.end()) {
      return 0;
    }

    for (auto &[c, count] : map_) {
      if (c != y) {
        int d = c - y;
        res += count[x] * py->second[x + d] * count[x + d];
        res += count[x] * py->second[x - d] * count[x - d];
      }
    }

    return res;
  }

private:
  map<int, map<int, int>> map_;
};

int main(int argc, char *argv[]) {
  DetectSquares obj;
  obj.add({3, 10});
  obj.add({11, 2});
  obj.add({3, 2});
  assert(obj.count({11, 10}) == 1);
  assert(obj.count({14, 8}) == 0);
  obj.add({11, 2});
  assert(obj.count({11, 10}) == 2);
  return 0;
}
