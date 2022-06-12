#include <iostream>
#include <set>
using namespace std;

class SeatManager {
private:
  set<int> s;

public:
  SeatManager(int n) {
    for (int i = 1; i <= n; i++) {
      s.emplace(i);
    }
  }

  int reserve() {
    auto x = *s.begin();
    s.erase(s.begin());
    return x;
  }

  void unreserve(int seatNumber) { s.emplace(seatNumber); }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
int main() {
  SeatManager seatManager{5};
  // 所有座位都可以预约，所以返回最小编号的座位，也就是 1 。
  cout << seatManager.reserve() << endl;
  // 可以预约的座位为 [2,3,4,5] ，返回最小编号的座位，也就是 2 。
  cout << seatManager.reserve() << endl;
  // 将座位 2 变为可以预约，现在可预约的座位为 [2,3,4,5] 。
  seatManager.unreserve(2);
  // 可以预约的座位为 [2,3,4,5] ，返回最小编号的座位，也就是 2 。
  cout << seatManager.reserve() << endl;
  // 可以预约的座位为 [3,4,5] ，返回最小编号的座位，也就是 3 。
  cout << seatManager.reserve() << endl;
  // 可以预约的座位为 [4,5] ，返回最小编号的座位，也就是 4 。
  cout << seatManager.reserve() << endl;
  // 唯一可以预约的是座位 5 ，所以返回 5 。
  cout << seatManager.reserve() << endl;
  // 将座位 5 变为可以预约，现在可预约的座位为 [5] 。
  seatManager.unreserve(5);

  return 0;
}
