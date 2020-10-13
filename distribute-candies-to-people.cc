#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people, 0);
        int start = 1, remains = candies, index = 0;

        while (remains > 0) {
            if (remains > start) {
                result[index++ % num_people] += start;
            } else {
                result[index++ % num_people] += remains;
            }
            remains -= start;
            start++;
        }

        return result;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int candies = stringToInteger(line);
        getline(cin, line);
        int num_people = stringToInteger(line);

        vector<int> ret = Solution().distributeCandies(candies, num_people);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
