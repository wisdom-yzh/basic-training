#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        const unsigned int size = primes.size();

        int pointer[size];
        std::fill(pointer, pointer + size, 0);

        int ugly[n];
        ugly[0] = 1;
        for (int i = 1; i < n; i++) {
            int min = INT_MAX;
            int minIndex = 0;
            for (int j = 0; j < primes.size(); j++) {
                int val = primes[j] * ugly[pointer[j]];
                if (min > val) {
                    min = val;
                    minIndex = j;
                } else if (min == val) {
                    pointer[j]++;
                }
            }
            pointer[minIndex]++;
            ugly[i] = min;
        }
        return ugly[n - 1];
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
        int n = stringToInteger(line);
        getline(cin, line);
        vector<int> primes = stringToIntegerVector(line);
        
        int ret = Solution().nthSuperUglyNumber(n, primes);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
