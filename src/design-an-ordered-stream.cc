#include <vector>
#include <string>
#include <iostream>
using namespace std;

class OrderedStream {
public:
    int ptr = 0;
    vector<string> slot;

    OrderedStream(int n): slot(vector<string>(n, "")) {}

    vector<string> insert(int idKey, string value) {
        int idx = idKey - 1;
        slot[idx] = value;

        vector<string> out;
        if (ptr == idx) {
            while (ptr != slot.size() && !slot[ptr].empty()) {
                out.push_back(slot[ptr++]);
            }
        }
        return out;
    }
};

int main() {
    OrderedStream os(5);
    os.insert(3, "ccccc"); // 插入 (3, "ccccc")，返回 []
    os.insert(1, "aaaaa"); // 插入 (1, "aaaaa")，返回 ["aaaaa"]
    os.insert(2, "bbbbb"); // 插入 (2, "bbbbb")，返回 ["bbbbb", "ccccc"]
    os.insert(5, "eeeee"); // 插入 (5, "eeeee")，返回 []
    os.insert(4, "ddddd"); // 插入 (4, "ddddd")，返回 ["ddddd", "eeeee"]
    return 0;
}
