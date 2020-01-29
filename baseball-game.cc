#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> scores;
        int points = 0;

        for (const auto &op: ops) {
            if (op == "C") {
                points -= scores[scores.size() - 1];
                scores.pop_back();
            } else if (op == "+") {
                int score = scores[scores.size() - 1] + scores[scores.size() - 2];
                scores.push_back(score);
                points += score;
            } else if (op == "D") {
                int score = 2 * scores[scores.size() - 1];
                scores.push_back(score);
                points += score;
            } else {
                int score = std::stoi(op);
                scores.push_back(score);
                points += score;
            }
        }
        return points;
    }
};

int main() {
    vector<string> ops {"5","-2","4","C","D","9","+","+"};
    cout << Solution().calPoints(ops);
    return 0;
}
