#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) {
            return 0;
        }
        auto p = std::max_element(citations.begin(), citations.end());
        vector<int> count(*p + 1);
        std::fill(count.begin(), count.end(), 0);
        for (size_t i = 0; i < citations.size(); i++) {
            int refCount = citations[i];
            for (int j = 0; j <= refCount; j++) {
                count[j]++;
            }
        }
        for (int i = count.size() - 1; i >= 0; i--) {
            if (count[i] >= i) {
                return i;
            }
        }
        return 0;
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
        vector<int> citations = stringToIntegerVector(line);
        
        int ret = Solution().hIndex(citations);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
