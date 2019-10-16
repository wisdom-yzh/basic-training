#include <vector>
#include <limits>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        std::map<std::string, int> dict1, dict2;
        for (int i = 0; i < list1.size(); i++) {
            dict1[list1[i]] = i;
        }
        for (int i = 0; i < list2.size(); i++) {
            dict2[list2[i]] = i;
        }

        vector<string> result;
        int minIndex = std::numeric_limits<int>::max();
        for (const auto &pair: dict1) {
            auto iter = dict2.find(pair.first);
            if (iter != dict2.end()) {
                if (minIndex > pair.second + iter->second) {
                    minIndex = pair.second + iter->second;
                    result.assign(1, pair.first);
                } else if (minIndex == pair.second + iter->second) {
                    result.push_back(pair.first);
                }
            }
        }

        return result;
    }
};

int main() {
    vector<string> list1 { "Shogun", "Tapioca Express", "Burger King", "KFC" };
    vector<string> list2 { "KFC","Shogun","Burger King" };

    std::cout << Solution().findRestaurant(list1, list2)[0];
    return 0;
}
