#include <string>
#include <iostream>
using namespace std;

class Trie {
private:
    struct TrieNode {
        int count;
        TrieNode *children[26];
    } *root;

    TrieNode *createNewTrieNode() {
        TrieNode *p = new TrieNode();
        p->count = 0;
        for (int i = 0; i < 26; i++) {
            p->children[i] = nullptr;
        }
        return p;
    }

    TrieNode *innerSearch(string &word) {
        TrieNode *p = root;
        for (auto ch: word) {
            p = p->children[ch - 'a'];
            if (p == nullptr) {
                break;
            }
        }
        return p;
    }

public:
    /** Initialize your data structure here. */
    Trie() {
        root = this->createNewTrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto *p = root;
        for (auto ch: word) {
            if (p->children[ch - 'a'] == nullptr) {
                p->children[ch - 'a'] = this->createNewTrieNode();
            }
            p = p->children[ch - 'a'];
        }
        p->count++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = this->innerSearch(word);
        if (p == nullptr) {
            return false;
        }
        return p->count;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return this->innerSearch(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
int main() {
    Trie *trie = new Trie();
    trie->insert("apple");
    cout << boolalpha << trie->search("apple") << endl;;
    cout << boolalpha << trie->search("app") << endl;
    cout << boolalpha << trie->startsWith("app") << endl;
    trie->insert("app");
    cout << boolalpha << trie->search("app") << endl;
    return 0;
}
