#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> result;

        std::sort(people.begin(), people.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        });

        for (auto &p: people) {
            result.insert(result.begin() + p.second, p);
        }
        
        return result;
    }
};

int main() {
    return 0;
}
