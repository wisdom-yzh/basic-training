#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> numbers(n);
        int index = 1;
        std::for_each(numbers.begin(), numbers.end(), [&](int &item) -> void {
            item = index++;
        });
        std::sort(numbers.begin(), numbers.end(), [](int &a, int &b) {
            return std::to_string(a) < std::to_string(b);
        });
        return numbers;
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
        int n = stringToInteger(line);
        
        vector<int> ret = Solution().lexicalOrder(n);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
