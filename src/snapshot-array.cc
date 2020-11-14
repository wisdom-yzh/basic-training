#include <iostream>
#include <vector>
#include <map>
using namespace std;

class SnapshotArray {
protected:
    std::map<int, int> arr;
    vector<map<int, int>> snapshots;

public:
    SnapshotArray(int length) {}

    void set(int index, int val) {
        arr[index] = val;
    }

    int snap() {
        snapshots.push_back(arr);
        return snapshots.size() - 1;
    }

    int get(int index, int snap_id) {
        return snapshots[snap_id][index];
    }
};

int main() {
    SnapshotArray arr(1000);
    return 0;
}
