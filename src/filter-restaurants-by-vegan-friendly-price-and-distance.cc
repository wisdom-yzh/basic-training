#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <tuple>
using namespace std;

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> filtered;

        std::copy_if(restaurants.begin(), restaurants.end(), std::back_inserter(filtered), [&] (vector<int> &r) {
            return (veganFriendly == 1 ? r[2] == veganFriendly : true) &&
                r[4] <= maxDistance &&
                r[3] <= maxPrice;
        });

        std::sort(filtered.begin(), filtered.end(), [](vector<int> &r1, vector<int> &r2) {
            return r1[1] != r2[1] ? r2[1] < r1[1] : r2[0] < r1[0];
        });

        vector<int> res;
        std::transform(filtered.begin(), filtered.end(), std::back_inserter(res), [](vector<int> r) {
            return r[0];
        });
        return res;
    }
};

int main() {
    vector<tuple<vector<vector<int>>, int, int, int>> testCases {
        {{{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}}, 1, 50, 10},
        {{{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}}, 0, 50, 10},
        {{{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}}, 0, 30, 3 }
    };
    for (auto &testCase: testCases) {
        for (auto &x: Solution().filterRestaurants(get<0>(testCase), get<1>(testCase),
                    get<2>(testCase), get<3>(testCase))) {
            cout << x << ' ';
        }
        cout << endl;
    }
}
