#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> result;
        if (nums1.empty() || nums2.empty()) {
            return result;
        }
        auto cmp = [](pair<int, int> p1, pair<int, int> p2) {
            return p1.first + p1.second > p2.first + p2.second;
        };
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (size_t i = 0; i < nums1.size(); i++) {
            for (size_t j = 0; j < nums2.size(); j++) {
               q.push(make_pair(nums1[i], nums2[j]));
            }
        }
        for (int i = 0; i < k; i++) {
            if (!q.empty()) {
                result.push_back(q.top());
                q.pop();
            } else {
                break;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
