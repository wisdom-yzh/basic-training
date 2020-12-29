#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class CombinationIterator {
public:
    string last;
    string current;
    string characters;
    int combinationLength;
    vector<int> indexes;

    CombinationIterator(string characters, int combinationLength):
        characters(characters),
        combinationLength(combinationLength) {

        this->last = this->characters.substr(this->characters.size() - combinationLength);
        indexes.assign(combinationLength, 0);
        current = "";
    }

    void first() {
        for (int i = 0; i < combinationLength; i++) {
            indexes[i] = i;
            current += characters[i];
        }
    }

    string next() {
        if (current.empty()) {
            this->first();
            return current;
        }

        if (!this->hasNext()) {
            return last;
        }

        int i = combinationLength - 1;

        for (; i >= 0; i--) {
            if (indexes[i] != characters.size() - 1 - (combinationLength - 1 - i)) {
                indexes[i]++;
                current[i] = characters[indexes[i]];
                break;
            }
        }
        for (int j = i + 1; j < combinationLength; j++) {
            indexes[j] = indexes[j - 1] + 1;
            current[j] = characters[indexes[j]];
        }

        return current;
    }

    bool hasNext() {
        return current != last;
    }
};

int main() {
    CombinationIterator c("abc", 2);
    cout << c.next() << boolalpha << ' ' << c.hasNext() << endl;
    cout << c.next() << boolalpha << ' ' << c.hasNext() << endl;
    cout << c.next() << boolalpha << ' ' << c.hasNext() << endl;
    cout << c.next() << boolalpha << ' ' << c.hasNext() << endl;
    return 0;
}
