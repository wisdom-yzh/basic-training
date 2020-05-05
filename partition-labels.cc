#include <vector>
#include <string>
#include <cassert>
#include <iostream>
#include <deque>
#include <tuple>
#include <array>
using namespace std;

class Solution {
public:
    inline int t(int idx) { return idx - 'a'; }

    vector<int> partitionLabels(string S) {
        std::array<int, 26> collection;
        std::fill(collection.begin(), collection.end(), -1);
        std::deque<std::pair<int, int>> stk;

        for (int i = 0; i < S.size(); i++) {
            if (collection[t(S[i])] == -1) {
                collection[t(S[i])] = t(S[i]);
                stk.push_back(std::make_pair(t(S[i]), 1));
            } else {
                int root = getRoot(collection, t(S[i]));
                int incrementSize = 1;
                while (true) {
                    auto &top = stk.back();
                    if (top.first == root) {
                        merge(collection, root, top.first);
                        top.second += incrementSize;
                        break;
                    }
                    merge(collection, root, top.first);
                    incrementSize += top.second;
                    stk.pop_back();
                }
            }
        }

        std::vector<int> result;
        for (const auto &item: stk) {
            result.push_back(item.second);
        }
        return result;
    }

    int getRoot(std::array<int, 26> &collection, int elem) {
        int root = elem;
        while (collection[root] != root) {
            root = collection[root];
        }
        return root;
    }

    void merge(std::array<int, 26> &collection, int elem1, int elem2) {
        collection[elem2] = getRoot(collection, elem1);
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
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
        string S = stringToString(line);

        vector<int> ret = Solution().partitionLabels(S);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
