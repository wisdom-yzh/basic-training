#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <bitset>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) {
            return false;
        }

        int N = sum / k;
        for (auto iter = nums.begin(); iter != nums.end();) {
            auto num = *iter;
            if (num == N) {
                k--;
                iter = nums.erase(iter);
            } else if (num < N) {
                iter++;
            } else {
                return false;
            }
        }

        vector<vector<map<uint16_t, bool>>> cache(N + 1, vector<map<uint16_t, bool>>(k + 1));
        std::bitset<16> indexUsed(0);
        return this->recursivePartition(nums, indexUsed, cache, N, N, k);
    }

    bool recursivePartition(vector<int> &nums, std::bitset<16> &indexUsed, vector<vector<map<uint16_t, bool>>> &cache,
            int N, int rest, int k) {

        if (k == 0) {
            return static_cast<uint16_t>(indexUsed.to_ulong()) == (1 << nums.size()) - 1;
        }

        if (rest == 0) {
            return this->recursivePartition(nums, indexUsed, cache, N, N, k - 1);
        }

        auto currentState = static_cast<uint16_t>(indexUsed.to_ulong());
        auto iter = cache[rest][k].find(currentState);
        if (iter != cache[rest][k].end()) {
            return iter->second;
        }

        bool result = false;
        for (int i = 0; i < nums.size() && !result; i++) {
            if (indexUsed[i] || nums[i] > rest) {
                continue;
            }

            indexUsed[i] = 1;
            if (this->recursivePartition(nums, indexUsed, cache, N, rest - nums[i], k)) {
                result = true;
            }
            indexUsed[i] = 0;
        }

        cache[rest][k].emplace(currentState, result);
        return result;
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

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);

        bool ret = Solution().canPartitionKSubsets(nums, k);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
