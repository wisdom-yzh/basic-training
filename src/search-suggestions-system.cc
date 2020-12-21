#include <vector>
#include <string>
#include <iostream>
#include <memory>
using namespace std;

class Solution {
private:
    struct Trie {
        Trie(string &&value = ""): value(value) {}
        string value;
        std::shared_ptr<Trie> children[26];
    };

    shared_ptr<Trie> root;

public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = make_shared<Trie>();
        vector<vector<string>> result(searchWord.size(), vector<string>());

        for (auto &str: products) {
            insertWord(str);
        }

        int i = 0;
        auto p = root;
        for (auto &ch: searchWord) {
            if (p != nullptr) {
                p = p->children[ch - 'a'];
            }
            dfs(p, result[i]);
            i++;
        }

        return result;
    }

    void insertWord(string &word) {
        auto p = root;
        for (auto &ch: word) {
            auto index = ch - 'a';
            if (p->children[index] == nullptr) {
                p->children[index] = make_shared<Trie>("");
            }
            p = p->children[index];
        }
        p->value = word;
    }

    void dfs(shared_ptr<Trie> p, vector<string> &res) {
        if (p == nullptr || res.size() == 3) {
            return;
        }

        if (!(p->value.empty())) {
            res.push_back(p->value);
        }

        for (auto &pChild: p->children) {
            dfs(pChild, res);
        }
    }
};

int main() {
    vector<pair<vector<string>, string>> testCases {
        { { "mobile","mouse","moneypot","monitor","mousepad" }, "mouse" },
        { { "havana" }, "havana" },
        { { "bags","baggage","banner","box","cloths" }, "bags" },
        { { "havana" }, "tatiana" }
    };
    for (auto &testCase: testCases) {
        for (auto &row: Solution().suggestedProducts(testCase.first, testCase.second)) {
            for (auto &str: row) {
                cout << str << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
