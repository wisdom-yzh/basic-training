#include <array>
#include <iostream>
using namespace std;

class ParkingSystem {
private:
    std::array<int, 3> arr;

public:
    ParkingSystem(int big, int medium, int small) {
        arr[0] = big;
        arr[1] = medium;
        arr[2] = small;
    }

    bool addCar(int carType) {
        if (arr[carType - 1] == 0) {
            return false;
        }
        arr[carType - 1]--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
auto main() -> int {
    ParkingSystem parkingSystem(1, 1, 0);
    cout << parkingSystem.addCar(1) << endl; // 返回 true ，因为有 1 个空的大车位
    cout << parkingSystem.addCar(2) << endl; // 返回 true ，因为有 1 个空的中车位
    cout << parkingSystem.addCar(3) << endl; // 返回 false ，因为没有空的小车位
    cout << parkingSystem.addCar(1) << endl; // 返回 false ，因为没有空的大车位，唯一一个大车位已经被占据了
    return 0;
}
