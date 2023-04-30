#include <cassert>
#include <string>
#include <vector>
using namespace std;

class Robot {
public:
  static constexpr char const *DIRS[] = {"East", "North", "West", "South"};
  static constexpr int const dx[] = {1, 0, -1, 0};
  static constexpr int const dy[] = {0, 1, 0, -1};

  Robot(int width, int height) : w_(width), h_(height), x_(0), y_(0), dir_(0) {}

  void step(int num) {
    num %= (w_ + h_ - 2) * 2;
    if (num == 0 && x_ == 0 && y_ == 0) {
      dir_ = 3;
    } else {
      while (num-- > 0) {
        if (!check(x_ + dx[dir_], y_ + dy[dir_])) {
          dir_ = (dir_ + 1) % 4;
        }
        x_ = x_ + dx[dir_];
        y_ = y_ + dy[dir_];
      }
    }
  }

  vector<int> getPos() { return {x_, y_}; }

  string getDir() { return DIRS[dir_]; }

private:
  int w_, h_;
  int dir_, x_, y_;

  bool check(int x, int y) { return x >= 0 && x < w_ && y >= 0 && y < h_; }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
int main(int argc, char *argv[]) {
  Robot robot(6, 3);
  robot.step(2);
  robot.step(2);
  auto pos = robot.getPos();
  assert(pos[0] == 4);
  assert(pos[1] == 0);
  assert(robot.getDir() == "East");
  robot.step(2);
  robot.step(1);
  robot.step(4);
  pos = robot.getPos();
  assert(pos[0] == 1);
  assert(pos[1] == 2);
  assert(robot.getDir() == "West");
  return 0;
}
