#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        std::sort(houses.begin(), houses.end());
        std::sort(heaters.begin(), heaters.end());
        vector<int> result(houses.size(), std::numeric_limits<int>::max());

        int heaterIndex = -1;
        for (int houseIndex = 0; houseIndex < houses.size(); houseIndex++) {
            int house = houses[houseIndex];
            int heater;
            do {
                heater = heaters[++heaterIndex];
                result[houseIndex] = std::min(result[houseIndex],
                        std::abs(heater - house));
            } while (heater < house && heaterIndex < heaters.size() - 1);

                if (heaterIndex >= 0) {
                    heaterIndex--;
                }
                if (heaterIndex >= 0) {
                    heaterIndex--;
                }
        }

        return *std::max_element(result.begin(), result.end());
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> houses = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> heaters = stringToIntegerVector(line);

        int ret = Solution().findRadius(houses, heaters);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
