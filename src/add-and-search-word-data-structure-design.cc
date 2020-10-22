#include <string>
#include <iostream>
using namespace std;

class WordDictionary {
private:
    struct TrieNode {
        bool isKey;
        TrieNode *children[26];
    } *root;

    TrieNode *createTrieNode() {
        TrieNode *p = new TrieNode();
        p->isKey = false;
        for (int i = 0; i < 26; i++) {
            p->children[i] = nullptr;
        }
        return p;
    }

    bool innerSearch(string &word, TrieNode *trieRoot) {
       auto *p = trieRoot;
        for (auto i = 0; i < static_cast<int>(word.size()); i++) {
            char ch = word[i];
            if (ch == '.') {
                bool matched = false;
                for (auto *subTrieRoot: p->children) {
                    if (matched) break;
                    if (subTrieRoot == nullptr) continue;
                    string subWord = word.substr(i + 1);
                    matched |= innerSearch(subWord, subTrieRoot);
                }
                return matched;
            }
            if (p->children[ch - 'a'] == nullptr) {
                return false;
            }
            p = p->children[ch - 'a'];
        }
        return p->isKey;
    }

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        this->root = createTrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto *p = root;
        for (auto &ch: word) {
            if (p->children[ch - 'a'] == nullptr) {
                p->children[ch - 'a'] = createTrieNode();
            }
            p = p->children[ch - 'a'];
        }
        p->isKey = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return this->innerSearch(word, this->root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
int main() {
    WordDictionary dict;
    dict.addWord("bad");
    dict.addWord("dad");
    dict.addWord("mad");
    cout << boolalpha << dict.search("pad") << endl;
    cout << boolalpha << dict.search("bad") << endl;
    cout << boolalpha << dict.search(".ad") << endl;
    cout << boolalpha << dict.search("b..") << endl;
    return 0;
}
