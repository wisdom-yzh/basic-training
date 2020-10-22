#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    enum State { WIN, LOSE };

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger * (1 + maxChoosableInteger) < desiredTotal) {
            return false;
        }
        if (desiredTotal <= 0 || maxChoosableInteger >= desiredTotal) {
            return true;
        }

        int choosableCollection = 0;
        for (int i = 0; i < maxChoosableInteger; i++) {
            choosableCollection <<= 1;
            choosableCollection++;
        }
        map<pair<int, int>, State> state;
        return canIWin(choosableCollection, desiredTotal, state) == State::WIN;
    }

    State canIWin(int choosableCollection, int desiredTotal, map<pair<int, int>, State> &state) {
        if (desiredTotal <= 0) {
            return State::WIN;
        }
        const auto & key = std::make_pair(choosableCollection, desiredTotal);
        auto p = state.find(key);
        if (p != state.end()) {
            return p->second;
        }

        State result = State::LOSE;

        for (int i = 1; i <= 20; i++) {
            if (!hasNumber(choosableCollection, i)) {
                continue;
            }
            if (i >= desiredTotal) {
                result = State::WIN;
                break;
            }
            int nextCollection = chooseNumber(choosableCollection, i);
            if (canIWin(nextCollection, desiredTotal - i, state) == State::LOSE) {
                result = State::WIN;
                break;
            }
        }

        state.emplace(key, result);
        return result;
    }

    int chooseNumber(int collection, int number) {
        return collection & (~(1 << (number - 1)));
    }

    bool hasNumber(int collection, int number) {
        return (collection & (1 << (number- 1))) != 0;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int maxChoosableInteger = stringToInteger(line);
        getline(cin, line);
        int desiredTotal = stringToInteger(line);

        bool ret = Solution().canIWin(maxChoosableInteger, desiredTotal);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
