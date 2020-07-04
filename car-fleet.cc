#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (position.empty()) {
            return 0;
        }

        vector<pair<int, double>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({ target - position[i], (target - position[i]) / (double)speed[i] });
        }

        std::sort(cars.begin(), cars.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first < b.first;
        });

        if (cars.size() == 1) {
            return 1;
        }

        int ans = 1;
        auto curr = cars.begin();
        for (auto iter = cars.begin() + 1; iter != cars.end(); iter++) {
            if (curr->second < iter->second) {
                ans++;
                curr = iter;
            }
        }
        return ans;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

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
        int target = stringToInteger(line);
        getline(cin, line);
        vector<int> position = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> speed = stringToIntegerVector(line);

        int ret = Solution().carFleet(target, position, speed);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
