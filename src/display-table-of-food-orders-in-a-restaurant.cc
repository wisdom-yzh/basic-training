#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> foodIndex;
        auto cmp = [](const string &a, const string &b) {
            return std::stoi(a) < std::stoi(b);
        };
        map<string, map<string, int>, decltype(cmp)> table(cmp);
        for (auto &order: orders) {
            const string &tableNum = order[1];
            const string &foodItem = order[2];

            table[tableNum][foodItem]++;
            foodIndex.emplace(foodItem);
        }


        vector<vector<string>> res;
        res.push_back(vector<string>(foodIndex.size() + 1, "Table"));
        std::copy(foodIndex.begin(), foodIndex.end(), next(res[0].begin()));

        for (auto &iter: table) {
            vector<string> row(foodIndex.size() + 1, "0");
            row[0] = iter.first;

            for (auto &food: iter.second) {
                int index = 1 + distance(foodIndex.begin(), foodIndex.find(food.first));
                row[index] = std::to_string(food.second);
            }

            res.push_back(row);
        }

        return res;
    }
};

int main() {
    vector<vector<vector<string>>> testCases {
        {
            {"David","3","Ceviche"},
            {"Corina","10","Beef Burrito"},
            {"David","3","Fried Chicken"},
            {"Carla","5","Water"},
            {"Carla","5","Ceviche"},
            {"Rous","3","Ceviche"}
        },
        {
            {"James","12","Fried Chicken"},
            {"Ratesh","12","Fried Chicken"},
            {"Amadeus","12","Fried Chicken"},
            {"Adam","1","Canadian Waffles"},
            {"Brianna","1","Canadian Waffles"}
        },
        {
            {"Laura","2","Bean Burrito"},
            {"Jhon","2","Beef Burrito"},
            {"Melissa","2","Soda"}
        }
    };
    for (auto &testCase: testCases) {
        for (auto &r: Solution().displayTable(testCase)) {
            for (auto &x: r) {
                cout << x << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
