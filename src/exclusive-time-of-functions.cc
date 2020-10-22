#include <vector>
#include <stack>
#include <sstream>
#include <iostream>
#include <tuple>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        std::stack<int> stk;
        vector<int> result(n);
        int prevTime = 0;
        for (const auto &log: logs) {
            int index, position, status;
            std::tie(index, status, position) = this->parse(log);
            if (!stk.empty()) {
                result[stk.top()] += position - prevTime;
            }
            prevTime = position;
            if (status == 0) {
                stk.push(index);
            } else {
                result[stk.top()]++;
                stk.pop();
                prevTime++;
            }
        }
        return result;
    }

    std::tuple<int, int, int> parse(const string &log) {
        int index, status, position;
        string str;
        istringstream iss(log);
        getline(iss, str, ':');
        index = std::stoi(str);
        getline(iss, str, ':');
        status = str == "start" ? 0 : 1;
        getline(iss, str, ':');
        position = std::stoi(str);
        return std::make_tuple(index, status, position);
    }
};

int main() {
    return 0;
}
