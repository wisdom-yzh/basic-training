#include <iostream>
#include <unordered_set>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto pair = s.insert(val);
        return pair.second;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto iter = s.find(val);
        if (iter == s.end()) {
            return false;
        }
        s.erase(iter);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        size_t offset = std::rand() % s.size();
        for (auto &v: s) {
            if (offset-- == 0) {
                return v;
            }
        }
        return *(s.begin());
    }

private:
    unordered_set<int> s;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
int main() {
    return 0;
}
